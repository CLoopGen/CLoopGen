#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    ARG_TYPE_STRING,
    ARG_TYPE_INTEGER,
    ARG_TYPE_DOUBLE,
    ARG_TYPE_KEY,
    ARG_TYPE_PATTERN,
    ARG_TYPE_UNIX_TIME,
    ARG_TYPE_PURE_TOKEN,
    ARG_TYPE_ONEOF,
    ARG_TYPE_BLOCK
} redisCommandArgType;

typedef struct cliCommandArg {
    char *name;
    redisCommandArgType type;
    char *token;
    char *since;
    int flags;
    int numsubargs;
    struct cliCommandArg *subargs;
    const char *display_text;
    int matched;
    int matched_token;
    int matched_name;
    int matched_all;
} cliCommandArg;

cliCommandArg *arg;
int i;

static cliCommandArg* alloc_cli_command_arg_array(size_t count) {
    cliCommandArg* arr = calloc(count, sizeof(cliCommandArg));
    for (size_t i = 0; i < count; i++) {
        arr[i].matched_all = 1;
        arr[i].numsubargs = 0;
        arr[i].subargs = NULL;
        arr[i].name = NULL;
        arr[i].token = NULL;
        arr[i].since = NULL;
        arr[i].display_text = NULL;
        arr[i].flags = 0;
        arr[i].matched = 0;
        arr[i].matched_token = 0;
        arr[i].matched_name = 0;
    }
    return arr;
}

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB to target 0.01 sec runtime
    const size_t avg_subargs_per_root = 8;
    const size_t num_roots = total_data_size / (sizeof(cliCommandArg) * avg_subargs_per_root);
    const size_t num_subargs = num_roots * avg_subargs_per_root;

    cliCommandArg* subargs_pool = alloc_cli_command_arg_array(num_subargs);
    cliCommandArg* root_args = alloc_cli_command_arg_array(num_roots);

    size_t sub_idx = 0;
    for (size_t r = 0; r < num_roots; r++) {
        size_t count = avg_subargs_per_root;
        if (sub_idx + count > num_subargs) count = num_subargs - sub_idx;
        root_args[r].numsubargs = count;
        root_args[r].subargs = &subargs_pool[sub_idx];
        root_args[r].matched_all = 1;
        sub_idx += count;
        if (sub_idx >= num_subargs) break;
    }

    arg = &root_args[0];
}