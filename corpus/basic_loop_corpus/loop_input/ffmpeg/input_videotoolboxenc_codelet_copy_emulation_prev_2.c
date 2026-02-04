#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
ssize_t dst_offset;
size_t dst_size;
int zeros;
int start_at;
int i;

static uint8_t *internal_dst_buffer = NULL;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    internal_dst_buffer = (uint8_t*)aligned_alloc(32, data_size);
    if (!internal_dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = internal_dst_buffer;
    dst_size = data_size;
    dst_offset = dst_size;

    start_at = 0;
    zeros = 0;
    i = 0;

    // Initialize buffer with pseudo-random data to ensure realistic cache behavior
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&data_size));
    for (size_t idx = 0; idx < data_size; idx++) {
        internal_dst_buffer[idx] = (rand() % 250 == 0) ? 0 : (rand() % 255 + 1);
    }
}