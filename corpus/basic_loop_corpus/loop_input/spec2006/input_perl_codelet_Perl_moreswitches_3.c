#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *e;

static char *buffer;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Initialize with printable characters, null-terminated at the end
    memset(buffer, 'x', data_size - 1);
    buffer[data_size - 1] = '\0';

    s = buffer;
    e = NULL;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}