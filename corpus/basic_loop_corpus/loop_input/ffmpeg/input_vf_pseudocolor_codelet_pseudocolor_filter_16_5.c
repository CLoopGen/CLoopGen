#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

int max = 65535;
int width = 1024;
int height = 512;
ptrdiff_t ilinesize = 2048;
ptrdiff_t slinesize = 2048;
ptrdiff_t dlinesize = 2048;

float *lut;
uint16_t *_usr_index;
uint16_t *src;
uint16_t *dst;
int x;
int y;

void init_vars() {
    const size_t total_pixels = (size_t)width * height;
    const size_t lut_size = 65536;

    lut = (float*)aligned_alloc(32, lut_size * sizeof(float));
    _usr_index = (uint16_t*)aligned_alloc(32, total_pixels * sizeof(uint16_t));
    src = (uint16_t*)aligned_alloc(32, total_pixels * sizeof(uint16_t));
    dst = (uint16_t*)aligned_alloc(32, total_pixels * sizeof(uint16_t));

    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < lut_size; i++) {
        lut[i] = (float)(rand() % (max + 1));
    }

    for (size_t i = 0; i < total_pixels; i++) {
        _usr_index[i] = rand() % lut_size;
        src[i] = rand() % 65536;
        dst[i] = 0;
    }
}