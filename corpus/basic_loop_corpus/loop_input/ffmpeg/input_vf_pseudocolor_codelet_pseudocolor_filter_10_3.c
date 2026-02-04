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
ptrdiff_t ilinesize;
ptrdiff_t slinesize;
ptrdiff_t dlinesize;
float *lut;
int x;
int y;

#define index _usr_index

void init_vars() {
    width = 1920;
    height = 1080;
    max = 255;

    ilinesize = width * 2;
    slinesize = width;
    dlinesize = width;

    _usr_index = (uint8_t*)aligned_alloc(32, ilinesize * height);
    src = (uint8_t*)aligned_alloc(32, slinesize * height);
    dst = (uint8_t*)aligned_alloc(32, dlinesize * height);
    lut = (float*)aligned_alloc(32, (max + 1) * 2 * sizeof(float));

    for (int i = 0; i < (max + 1) * 2; i++) {
        lut[i] = (i % (max + 2)) - 10;
    }

    for (int i = 0; i < ilinesize * height; i++) {
        _usr_index[i] = rand() % ((max + 1) * 2);
    }

    for (int i = 0; i < slinesize * height; i++) {
        src[i] = rand() % (max + 1);
    }

    for (int i = 0; i < dlinesize * height; i++) {
        dst[i] = 0;
    }
}