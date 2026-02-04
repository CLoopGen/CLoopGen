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
    buffer_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on typical CPU
    buffer = (char*)malloc(buffer_size);
    if (!buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data
    memset(buffer, 'x', buffer_size - 1);
    buffer[buffer_size - 1] = '\0'; // null-terminate at the end

    s = buffer;
    len = buffer_size;
    i = 0;
}