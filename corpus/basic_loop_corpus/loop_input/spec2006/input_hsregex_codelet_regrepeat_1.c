#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct exec {
    char *reginput;
    char *regbol;
    char **regstartp;
    char **regendp;
};

struct exec *ep;
size_t count;
char *scan;
char ch;

static char *buffer = NULL;
static char **ptr_array = NULL;

void init_vars() {
    const size_t data_size = 64 << 20; // 64 MB of input data

    buffer = (char *)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    ptr_array = (char **)calloc(2, sizeof(char *));
    if (!ptr_array) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    memset(buffer, 'A', data_size);
    buffer[data_size - 1] = '\0';

    ep = (struct exec *)malloc(sizeof(struct exec));
    if (!ep) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    ep->reginput = buffer;
    ep->regbol = buffer;
    ep->regstartp = &ptr_array[0];
    ep->regendp = &ptr_array[1];

    scan = NULL;
    count = 0;
    ch = 'A';
}