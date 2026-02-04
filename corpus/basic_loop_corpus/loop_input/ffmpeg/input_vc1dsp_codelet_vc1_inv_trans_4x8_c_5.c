#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int t1;
int t2;
int t3;
int t4;

static int16_t *src_storage;
static int16_t *dst_storage;

int16_t *src;
int16_t *dst;

void init_vars() {
    size_t total_size = 1 << 20; // 1MB of data (each int16_t is 2 bytes)
    size_t num_elements = total_size / sizeof(int16_t);
    
    // Ensure we have enough elements for the loop: each iteration uses 4 input and output elements,
    // and runs 8 times per block, with src/dst incremented by 8 each time.
    // So we need at least 8 * 8 = 64 elements per block. Allocate one block.
    num_elements = 64 * 1024; // Enough for 1024 iterations of outer structure if needed

    src_storage = (int16_t*)aligned_alloc(32, num_elements * sizeof(int16_t));
    dst_storage = (int16_t*)aligned_alloc(32, num_elements * sizeof(int16_t));

    if (!src_storage || !dst_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        src_storage[idx] = rand() % 1000 - 500;
        dst_storage[idx] = 0;
    }

    src = src_storage;
    dst = dst_storage;
}