#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int max = 255;
int width = 1920;
int height = 1080;
uint8_t *_usr_index;
uint8_t *src;
uint8_t *dst;
ptrdiff_t ilinesize = 1920;
ptrdiff_t slinesize = 1920;
ptrdiff_t dlinesize = 1920;
float *lut;
int x;
int y;

void init_vars() {
    size_t total_size = width * height;

    _usr_index = (uint8_t*)aligned_alloc(32, total_size * sizeof(uint8_t));
    src = (uint8_t*)aligned_alloc(32, total_size * sizeof(uint8_t));
    dst = (uint8_t*)aligned_alloc(32, total_size * sizeof(uint8_t));
    lut = (float*)aligned_alloc(32, 256 * sizeof(float));

    for (size_t i = 0; i < total_size; i++) {
        _usr_index[i] = rand() % 256;
        src[i] = rand() % 256;
    }

    for (int i = 0; i < 256; i++) {
        lut[i] = (i % 2 == 0) ? i : -1;
    }
}