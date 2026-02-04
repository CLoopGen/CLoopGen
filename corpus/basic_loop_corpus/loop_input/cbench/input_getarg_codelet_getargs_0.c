#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int j;
int argc = 0;
char **argv = NULL;
int i = 0;
int off = 1;

static char **local_argv = NULL;
static int max_args = 256;
static int arg_size = 1024 * 1024; // ~1MB per string

void init_vars() {
    argc = (arg_size / sizeof(char*)) - off; // ensure j + off is in bounds
    if (argc <= 0) argc = 1;
    if (argc > max_args) argc = max_args;

    i = 0;
    off = 1;
    j = 0;

    local_argv = malloc((argc + off + 1) * sizeof(char*));
    if (!local_argv) exit(1);

    for (int idx = 0; idx < argc + off + 1; idx++) {
        local_argv[idx] = malloc(arg_size);
        if (!local_argv[idx]) exit(1);
        memset(local_argv[idx], 'A' + (idx % 26), arg_size - 1);
        local_argv[idx][arg_size - 1] = '\0';
    }

    argv = local_argv;
}