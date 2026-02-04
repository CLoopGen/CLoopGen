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
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPUs
    internal_buffer = (char *)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data
    memset(internal_buffer, 'x', data_size - 1);
    // Null terminate at a random position near the end to ensure loop runs long
    size_t null_pos = data_size - (rand() % (data_size / 10)) - 1;
    if (null_pos >= data_size) null_pos = data_size - 1;
    internal_buffer[null_pos] = '\0';

    s = internal_buffer;
    len = data_size;
    i = 0;
}