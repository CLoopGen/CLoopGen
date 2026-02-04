#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int i;

static uint8_t *allocated_dst;
static uint8_t *allocated_src;

void init_vars() {
    h = 1000000;  
    dstStride = 8;
    srcStride = 8;

    size_t total_size = (size_t)h * 8;
    allocated_dst = aligned_alloc(8, total_size);
    allocated_src = aligned_alloc(8, total_size);

    if (!allocated_dst || !allocated_src) {
        exit(1);
    }

    dst = allocated_dst;
    src = allocated_src;

    for (size_t idx = 0; idx < total_size; idx++) {
        allocated_src[idx] = (uint8_t)(idx & 0xFF);
    }
}

__attribute__((destructor))
static void cleanup() {
    free(allocated_dst);
    free(allocated_src);
}