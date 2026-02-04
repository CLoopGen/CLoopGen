#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int max = 255;
int width = 1920;
int height = 1080;
uint8_t *_usr_index;
uint8_t *src;
uint8_t *dst;
ptrdiff_t ilinesize = 1920 / 2;
ptrdiff_t slinesize = 1920;
ptrdiff_t dlinesize = 1920;
float *lut;
int x;
int y;

void init_vars() {
    size_t total_pixels = (size_t)width * height;
    size_t index_size = total_pixels / 2 + 16; // account for shift and alignment
    size_t src_dst_size = total_pixels;
    size_t lut_size = 256;

    _usr_index = (uint8_t*)aligned_alloc(32, index_size);
    src = (uint8_t*)aligned_alloc(32, src_dst_size);
    dst = (uint8_t*)aligned_alloc(32, src_dst_size);
    lut = (float*)aligned_alloc(32, lut_size * sizeof(float));

    for (size_t i = 0; i < index_size; i++) {
        _usr_index[i] = rand() % 256;
    }
    for (size_t i = 0; i < src_dst_size; i++) {
        src[i] = rand() % 256;
    }
    for (size_t i = 0; i < lut_size; i++) {
        float val = (i * 1.5f); 
        lut[i] = fmaxf(0.0f, fminf(val, 300.0f));
    }

    max = 255;
    width = 1920;
    height = 1080;
    ilinesize = width / 2;
    slinesize = width;
    dlinesize = width;
}