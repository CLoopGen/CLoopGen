#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t permutation[64];
int i;

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src_buffer;

void init_vars() {
    size_t data_size = 67108864; // 64 MB for ~0.01 sec runtime on modern CPU

    internal_dst_buffer = aligned_alloc(32, data_size);
    internal_src_buffer = aligned_alloc(32, data_size);

    if (!internal_dst_buffer || !internal_src_buffer) {
        exit(1);
    }

    dst = internal_dst_buffer;
    src = internal_src_buffer;

    for (size_t idx = 0; idx < data_size; idx++) {
        src[idx] = rand() % 64;
    }

    for (int idx = 0; idx < 64; idx++) {
        permutation[idx] = rand() % 256;
    }
}