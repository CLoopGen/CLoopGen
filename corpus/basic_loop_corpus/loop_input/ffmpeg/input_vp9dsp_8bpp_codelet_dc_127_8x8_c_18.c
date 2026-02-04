#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
uint8_t *dst;
uint32_t val;
int y;

static uint8_t *buffer;
static size_t buffer_size = 1 << 20; // 1MB for ~0.01 sec runtime

void init_vars() {
    // Initialize val to a non-zero value
    val = 0xCAFEBABE;
    
    // Set stride to 8 bytes per row (covers 8 iterations * 8 bytes written per iteration)
    stride = 8;
    
    // Allocate buffer with safety margin: 8 rows * stride + some extra to prevent overflow
    buffer_size = 8 * stride + 64;
    buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    memset(buffer, 0, buffer_size);
    
    // Initialize dst to start of buffer
    dst = buffer;
    
    // Initialize y to zero (loop control)
    y = 0;
}

__attribute__((destructor))
static void cleanup() {
    if (buffer) {
        free(buffer);
        buffer = NULL;
    }
}