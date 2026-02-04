#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec runtime on modern CPUs
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data, but place a null terminator near the end
    memset(buffer, 'A', data_size);
    buffer[data_size - 1] = '\0'; // Null terminate at the last position

    s = buffer;
    len = data_size;
    i = 0;
}