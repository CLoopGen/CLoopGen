#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on typical CPU
    internal_buffer = (char *)malloc(buffer_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill with non-null bytes to ensure loop runs through most of the buffer
    memset(internal_buffer, 'A', buffer_size - 1);
    internal_buffer[buffer_size - 1] = '\0'; // Null terminate at end

    s = internal_buffer;
    len = buffer_size;
    i = 0;
}