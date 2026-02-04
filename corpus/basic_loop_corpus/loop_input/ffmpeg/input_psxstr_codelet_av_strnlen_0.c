#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 128 * 1024 * 1024; // 128 MB
    buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        buffer_size = 64 * 1024 * 1024; // Fallback to 64 MB
        buffer = (char *)malloc(buffer_size);
        if (!buffer) exit(1);
    }

    memset(buffer, 'x', buffer_size - 1);
    buffer[buffer_size - 1] = '\0';

    s = buffer;
    len = buffer_size;
}