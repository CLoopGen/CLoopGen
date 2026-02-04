#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t *src_buf;
static uint8_t *dst_buf;
static size_t src_size;
static size_t dst_capacity;

void init_vars() {
    src_size = 67108864; // 64 MB to target ~0.01 sec runtime on modern CPU
    dst_capacity = src_size + 65536;

    src_buf = aligned_alloc(64, src_size);
    dst_buf = aligned_alloc(64, dst_capacity);

    if (!src_buf || !dst_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buf[idx] = rand() % 256;
    }

    // Ensure no out-of-bounds access by avoiding pattern at boundaries
    // Prevent triggering the condition near edges: src[-2], src[-1], src[1]
    for (int j = 0; j < 3; j++) {
        if (j < src_size) src_buf[j] = 1;
    }
    if (src_size > 1) src_buf[src_size-1] = 1;

    // Initialize global variables
    src = src_buf;
    size = (int)src_size;
    dst = dst_buf;
    dsize = 0;
    i = 0;
}