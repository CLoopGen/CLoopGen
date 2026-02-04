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
    size_t target_size = 64 * 1024 * 1024; // 64 MB to ensure ~0.01 sec runtime on modern CPUs
    internal_buffer = (char *)malloc(target_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data, but place a null terminator near the end
    memset(internal_buffer, 'x', target_size - 1);
    internal_buffer[target_size - 1] = '\0';

    s = internal_buffer;
    len = target_size;
}