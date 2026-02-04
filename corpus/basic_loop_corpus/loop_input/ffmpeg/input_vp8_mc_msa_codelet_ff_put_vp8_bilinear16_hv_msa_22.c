#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint8_t *src;
ptrdiff_t src_stride;
int height;
uint32_t loop_cnt;

static uint8_t *internal_src_storage;
static uint8_t *internal_dst_storage;

void init_vars() {
    const int data_size_mb = 64;
    const size_t total_elements = (size_t)data_size_mb * 1024 * 1024;
    
    internal_src_storage = aligned_alloc(32, total_elements);
    internal_dst_storage = aligned_alloc(32, total_elements);
    
    if (!internal_src_storage || !internal_dst_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_elements; ++i) {
        internal_src_storage[i] = rand() & 0xFF;
        internal_dst_storage[i] = rand() & 0xFF;
    }

    src_stride = 1024;
    dst_stride = 1024;
    height = 1024;

    src = internal_src_storage;
    dst = internal_dst_storage;
}