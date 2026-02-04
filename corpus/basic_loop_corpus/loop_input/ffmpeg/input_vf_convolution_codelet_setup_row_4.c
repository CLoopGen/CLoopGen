#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int radius = 15;

uint8_t *c[32]; // Support up to radius*2+1 = 31 pointers safely

uint8_t *src;
int stride;
int x = 1000;
int w = 2000;
int y = 500;
int bpc = 4;
int i;

void init_vars() {
    // Set radius such that loop runs sufficiently long (~0.01 sec)
    radius = 15;  // This gives 31 iterations, which is reasonable

    // Allocate source image data: aim for ~64MB to ensure runtime
    size_t total_size = (size_t)w * (y + 2 * radius) * bpc;
    if (total_size < (1 << 20)) { // If too small, scale up
        w = 4096;
        y = 4000;
        total_size = (size_t)w * (y + 2 * radius) * bpc;
    }

    src = (uint8_t*)aligned_alloc(32, total_size);
    if (!src) exit(1);

    stride = w * bpc;

    // Ensure all c[i] pointers will be within bounds when accessed
    for (i = 0; i < radius * 2 + 1; i++) {
        int xoff = (x + i - radius);
        if (xoff < 0) xoff = -xoff;
        if (xoff >= w) xoff = 2 * w - 1 - xoff;
        // Just precompute valid offsets; actual assignment happens in loop
    }
}