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

void init_vars() {
    const size_t target_size = 128 * 1024 * 1024; // 128 MB
    internal_buffer = (char *)malloc(target_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill with non-null data to force loop to iterate through most of the buffer
    memset(internal_buffer, 'x', target_size - 1);
    internal_buffer[target_size - 1] = '\0'; // Null terminator at end

    s = internal_buffer;
    len = target_size;
    i = 0;
}