#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

ptrdiff_t top_linesize;
ptrdiff_t bottom_linesize;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
uint16_t *top;
uint16_t *bottom;
uint16_t *dst;
double opacity;
int i;
int j;

void init_vars() {
    // Set image dimensions to achieve ~100ms runtime
    // Each pixel does several arithmetic operations; estimate 20-30 cycles per pixel
    // On a 3GHz CPU, 1M pixels ≈ 10ms. Use 1920x1080 as realistic size (~2M pixels)
    width = 1920;
    height = 1080;

    // Line sizes in bytes, aligned to 32-byte boundary for potential SIMD alignment
    ptrdiff_t line_bytes = ((width * sizeof(uint16_t) + 31) / 32) * 32;
    top_linesize = line_bytes / sizeof(uint16_t);
    bottom_linesize = line_bytes / sizeof(uint16_t);
    dst_linesize = line_bytes / sizeof(uint16_t);

    opacity = 0.75; // Typical alpha value

    // Allocate buffers with proper sizing including linesize padding
    size_t total_size = dst_linesize * height * sizeof(uint16_t);
    top = (uint16_t*)aligned_alloc(32, total_size);
    bottom = (uint16_t*)aligned_alloc(32, total_size);
    dst = (uint16_t*)aligned_alloc(32, total_size);

    // Initialize top and bottom with gradient pattern to avoid constant folding
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            top[y * top_linesize + x] = (uint16_t)((x + y) % 1024);
            bottom[y * bottom_linesize + x] = (uint16_t)((x * y + 123) % 1024);
        }
    }

    // Zero out destination
    memset(dst, 0, total_size);
}