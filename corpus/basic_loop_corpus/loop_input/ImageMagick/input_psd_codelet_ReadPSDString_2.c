#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

char *p;
char *q;

static char *buffer;
static size_t buffer_size = 128 * 1024 * 1024; // 128 MB

void init_vars() {
    buffer = (char *)aligned_alloc(32, buffer_size);
    if (!buffer) {
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; ++i) {
        buffer[i] = (char)(i & 0xFF);
    }

    p = buffer;
    q = buffer + buffer_size - 1;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}