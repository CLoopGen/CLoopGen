#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int max = 255;
int width = 1920;
int height = 1080;
uint8_t *_usr_index;
uint8_t *src;
uint8_t *dst;
ptrdiff_t ilinesize = 3840;
ptrdiff_t slinesize = 1920;
ptrdiff_t dlinesize = 1920;
float *lut;
int x;
int y;

#define index _usr_index

void init_vars() {
    // Allocate image data
    src = aligned_alloc(32, (size_t)height * (size_t)slinesize);
    dst = aligned_alloc(32, (size_t)height * (size_t)dlinesize);
    _usr_index = aligned_alloc(32, (size_t)(height * 2) * (size_t)ilinesize);

    // Allocate and initialize LUT (map index to float value in valid range)
    lut = aligned_alloc(32, 256 * sizeof(float));
    for (int i = 0; i < 256; i++) {
        lut[i] = (float)((i * 3) % 256); // maps to [0, 255]
    }

    // Ensure max is within lut output range
    max = 255;

    // Initialize src and index with sample data
    for (int i = 0; i < height * slinesize; i++) {
        src[i] = rand() % 256;
    }
    for (int i = 0; i < (height * 2) * ilinesize; i++) {
        index[i] = rand() % 256;
    }
    for (int i = 0; i < height * dlinesize; i++) {
        dst[i] = 0;
    }
}