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

struct cliCommandArg {
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
};

#define DATA_SIZE (128 << 20)  // 128 MB

struct cliCommandArg *args = NULL;
int *numargs = NULL;
int i = 0;
int j = 0;

void init_vars() {
    args = calloc(DATA_SIZE, sizeof(struct cliCommandArg));
    if (!args) exit(1);

    numargs = malloc(sizeof(int));
    if (!numargs) exit(1);

    *numargs = DATA_SIZE;

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        args[idx].name = NULL;
        args[idx].type = ARG_TYPE_STRING;
        args[idx].token = NULL;
        args[idx].since = NULL;
        args[idx].flags = 0;
        args[idx].numsubargs = 0;
        args[idx].subargs = NULL;
        args[idx].display_text = NULL;
        args[idx].matched = 0;
        args[idx].matched_token = 0;
        args[idx].matched_name = 0;
        args[idx].matched_all = 0;
    }

    i = 0;
}