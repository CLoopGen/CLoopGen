#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int num_pixels;
uint8_t *palette;
int i;

void init_vars() {
    // Aim for approximately 64M pixels to target ~0.01 sec on modern CPUs
    num_pixels = 64 * (1 << 20);  // 64 million pixels

    // Allocate src: each pixel uses 2 bytes (index into palette and byte for shift)
    src = (uint8_t*)aligned_alloc(32, num_pixels * 2);
    // dst: each output is uint32_t
    dst = (uint8_t*)aligned_alloc(32, num_pixels * sizeof(uint32_t));
    // palette: array of uint32_t, assume indexed by byte values (256 entries)
    palette = (uint8_t*)aligned_alloc(32, 256 * sizeof(uint32_t));

    // Initialize src with valid indices: [i<<1] in [0,255], [(i<<1)+1] in [0,255]
    for (int j = 0; j < num_pixels * 2; j++) {
        src[j] = rand() & 0xFF;
    }

    // Initialize palette with arbitrary uint32_t values
    for (int j = 0; j < 256; j++) {
        ((uint32_t*)palette)[j] = rand() ^ (rand() << 16);
    }
}