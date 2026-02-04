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
    num_pixels = 32 << 20; // 32 million pixels -> ~128MB for dst, adjust as needed for ~0.01s runtime

    src = aligned_alloc(32, num_pixels * 2);
    dst = aligned_alloc(32, num_pixels * sizeof(uint32_t));
    palette = aligned_alloc(32, 256 * sizeof(uint32_t));

    if (!src || !dst || !palette) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < num_pixels * 2; j++) {
        src[j] = rand() % 256;
    }

    for (int j = 0; j < 256; j++) {
        ((uint32_t *)palette)[j] = rand();
    }

    i = 0;
}