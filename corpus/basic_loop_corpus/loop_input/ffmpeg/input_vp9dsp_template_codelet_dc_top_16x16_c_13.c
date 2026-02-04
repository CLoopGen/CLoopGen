#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
uint8_t *dst;
uint32_t dc;
int y;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB to target ~0.01 sec runtime
static uint8_t *buffer;

void init_vars() {
    // Initialize dc to a non-zero pattern for visibility
    dc = 0xdeadbeefU;

    // Allocate large enough buffer to ensure many iterations over rows
    buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Set dst to start of buffer
    dst = buffer;

    // Stride is typically aligned; set to 16-byte aligned row width
    stride = 16;
}

// Cleanup function to avoid memory leaks (if needed in test harness)
void cleanup_vars() {
    if (buffer) {
        free(buffer);
        buffer = NULL;
    }
}