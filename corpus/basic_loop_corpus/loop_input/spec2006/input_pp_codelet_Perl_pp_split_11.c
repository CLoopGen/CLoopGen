#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

char *s;
char *strend;
char *m;

static char *buffer;
static size_t buffer_size = 128 * 1024 * 1024; // 128 MB

void init_vars() {
    buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        exit(1);
    }

    s = buffer;
    strend = buffer + buffer_size;

    memset(buffer, 'x', buffer_size - 1);
    buffer[buffer_size - 1] = '\n';

    m = NULL;
}