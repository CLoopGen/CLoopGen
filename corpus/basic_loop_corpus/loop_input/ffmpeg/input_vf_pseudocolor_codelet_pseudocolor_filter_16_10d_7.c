#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int max = 65535;
int width = 1024;
int height = 512;
ptrdiff_t ilinesize = 1024 * sizeof(uint16_t);
ptrdiff_t slinesize = 1024 * sizeof(uint16_t);
ptrdiff_t dlinesize = 1024 * sizeof(uint16_t);

float *lut;
uint16_t *_usr_index;
uint16_t *src;
uint16_t *dst;
int x;
int y;

void init_vars() {
    size_t total_size = width * height;
    size_t lut_size = total_size / 2 + 1; // index[x >> 1] implies half as many

    lut = (float *)aligned_alloc(32, lut_size * sizeof(float));
    _usr_index = (uint16_t *)aligned_alloc(32, total_size * sizeof(uint16_t));
    src = (uint16_t *)aligned_alloc(32, total_size * sizeof(uint16_t));
    dst = (uint16_t *)aligned_alloc(32, total_size * sizeof(uint16_t));

    for (size_t i = 0; i < lut_size; i++) {
        lut[i] = (float)(i % (max + 1)); 
    }

    for (size_t i = 0; i < total_size; i++) {
        _usr_index[i] = rand() % lut_size;
        src[i] = rand() % (max + 1);
        dst[i] = 0;
    }
}