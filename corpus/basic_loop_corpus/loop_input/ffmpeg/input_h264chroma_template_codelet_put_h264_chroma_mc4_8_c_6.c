#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int B;
int C;
int D;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Set constants
    A = 10;
    B = 20;
    C = 30;
    D = 40;
    h = 512;
    stride = 1024;  // Ensure sufficient padding per row

    // Allocate buffers with enough space to prevent out-of-bounds access
    // Each loop iteration accesses src[0..4] and src[stride+0..stride+4]
    // So we need at least (h * stride) + stride + 5 bytes
    size_t buffer_size = (h * stride) + stride + 5;
    
    src_buffer = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));
    dst_buffer = (uint8_t*)calloc(buffer_size, sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    // Initialize source data to non-zero for meaningful computation
    for (size_t idx = 0; idx < buffer_size; idx++) {
        src_buffer[idx] = idx & 0xFF;
    }

    // Set pointers
    src = src_buffer;
    dst = dst_buffer;
}