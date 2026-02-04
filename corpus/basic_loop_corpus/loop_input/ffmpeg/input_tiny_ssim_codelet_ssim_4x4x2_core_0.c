#include <stdint.h>
#include <stdlib.h>

typedef uint8_t pixel;

pixel *pix1;
intptr_t stride1;
pixel *pix2;
intptr_t stride2;
int sums[2][4];
int x;
int y;
int z;

static pixel *pix1_storage;
static pixel *pix2_storage;

void init_vars() {
    const int total_pixels = 64 * 1024 * 1024; // ~64MB per buffer
    pix1_storage = (pixel *)aligned_alloc(32, total_pixels);
    pix2_storage = (pixel *)aligned_alloc(32, total_pixels);

    for (int i = 0; i < total_pixels; i++) {
        pix1_storage[i] = rand() & 0xFF;
        pix2_storage[i] = rand() & 0xFF;
    }

    stride1 = 16;
    stride2 = 16;

    pix1 = pix1_storage;
    pix2 = pix2_storage;
}