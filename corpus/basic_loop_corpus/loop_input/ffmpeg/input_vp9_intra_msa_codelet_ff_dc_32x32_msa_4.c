#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint32_t row;

static uint8_t *allocated_memory = NULL;

void init_vars() {
    size_t total_size = 64 * 1024 * 1024; // 64 MB of data
    dst_stride = 32;
    
    allocated_memory = (uint8_t*)aligned_alloc(32, total_size);
    if (!allocated_memory) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    dst = allocated_memory;
}