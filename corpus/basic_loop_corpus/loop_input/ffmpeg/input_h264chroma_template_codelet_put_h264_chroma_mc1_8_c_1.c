#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;
int E;
int step;

uint8_t *dst_buffer;
uint8_t *src_buffer;

void init_vars() {
    // Set computational parameters
    A = 17; 
    E = 31;
    step = 4;
    h = 4096;
    stride = 8192;  // Ensure sufficient spacing

    // Allocate buffers with enough data to achieve desired runtime
    // Aim for ~64MB total data to ensure loop runs long enough (~0.01 sec on modern CPU)
    size_t buffer_size = (size_t)stride * h + step + 64;
    src_buffer = (uint8_t*)aligned_alloc(64, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, stride * h);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (size_t idx = 0; idx < buffer_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 251);
    }

    // Initialize pointers
    src = src_buffer;
    dst = dst_buffer;
}