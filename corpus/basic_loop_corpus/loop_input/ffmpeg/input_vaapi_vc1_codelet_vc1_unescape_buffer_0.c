#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t src_size;
static size_t dst_capacity;

void init_vars() {
    src_size = 64 << 20; // 64 MB input size for ~0.01 sec runtime on modern CPU
    dst_capacity = src_size + 32; // slightly larger to prevent overflow

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_capacity);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; ++idx) {
        src_buffer[idx] = rand() % 8;
    }

    src = src_buffer;
    dst = dst_buffer;
    size = (int)src_size;
    dsize = 0;
    i = 0;
}