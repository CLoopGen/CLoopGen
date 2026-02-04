#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
ptrdiff_t stride;
int *color_tab;
int mono;
int offset;
int pix_size;
uint8_t indices[16];
int x;
int y;

void init_vars() {
    // Set pixel size and offset
    pix_size = 4;           // Assume 4 bytes per pixel (e.g., RGBA)
    offset = 0;              // No additional offset within pixel
    mono = 0;                // Default to non-mono (full 32-bit pixel write)

    // Allocate color table (256 entries for palette lookup)
    color_tab = (int*)malloc(256 * sizeof(int));
    for (int i = 0; i < 256; i++) {
        // Simulate a gradient or valid color values: R=G=B = i, alpha = 255
        color_tab[i] = ((i << 0) | (i << 8) | (i << 16) | (255U << 24));
    }

    // Initialize indices with safe values in [0, 255]
    for (int i = 0; i < 16; i++) {
        indices[i] = i * 10 % 256;  // Spread indices across the range
    }

    // Stride is width in bytes; assume 4x4 block but aligned to larger row size
    stride = 16 * pix_size;  // Row stride of 16 pixels (for padding or image width)

    // Total buffer size: ensure we cover at least y=0..3, x=0..3 with stride
    size_t total_size = (size_t)(4) * (size_t)stride;  // 4 rows
    dst = (uint8_t*)malloc(total_size);
    if (!dst) {
        fprintf(stderr, "Failed to allocate dst\n");
        exit(1);
    }
    // Zero-initialize destination to avoid garbage
    for (size_t i = 0; i < total_size; i++) {
        dst[i] = 0;
    }

    // Reset loop counters
    x = 0;
    y = 0;
}