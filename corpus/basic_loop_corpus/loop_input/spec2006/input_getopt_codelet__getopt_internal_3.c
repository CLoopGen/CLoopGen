#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *gg_optarg;
char *nextchar;
char *nameend;

static char *buffer;
static size_t data_size = 1 << 20; // 1MB

void init_vars() {
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Fill with non-null, non-'=' characters for most of the buffer
    memset(buffer, 'x', data_size - 1);
    buffer[data_size - 1] = '=';

    gg_optarg = buffer;
    nextchar = NULL;
    nameend = NULL;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}