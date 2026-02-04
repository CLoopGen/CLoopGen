#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB to target ~0.01s runtime

static uint8_t *dst_data;
static uint8_t *src_data;

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h;
int A = 17;
int B = 23;
int C = 19;
int D = 29;
int i;

void init_vars() {
    const int width = 1024;
    h = DATA_SIZE / width;
    if (h < 1) h = 1;
    
    stride = width + 8; // Ensure sufficient padding for safe access
    
    size_t total_size = (h + 2) * stride * sizeof(uint8_t);
    
    dst_data = aligned_alloc(32, total_size);
    src_data = aligned_alloc(32, total_size);
    
    if (!dst_data || !src_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < total_size; i++) {
        dst_data[i] = rand() % 256;
        src_data[i] = rand() % 256;
    }
    
    dst = dst_data + stride + 4;
    src = src_data + stride + 4;
}