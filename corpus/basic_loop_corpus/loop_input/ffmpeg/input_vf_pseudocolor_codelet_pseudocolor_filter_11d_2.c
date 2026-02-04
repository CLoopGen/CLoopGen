#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int max = 255;
int width = 1024;
int height = 512;
uint8_t *_usr_index;
uint8_t *src;
uint8_t *dst;
ptrdiff_t ilinesize = 512;
ptrdiff_t slinesize = 1024;
ptrdiff_t dlinesize = 1024;
float *lut;
int x;
int y;

#define index _usr_index

void init_vars() {
    size_t iindex_size = ((height >> 1) + 1) * ilinesize;
    size_t src_size = (size_t)height * slinesize;
    size_t dst_size = (size_t)height * dlinesize;
    size_t lut_size = 256 * sizeof(float);

    _usr_index = (uint8_t*)calloc(iindex_size, sizeof(uint8_t));
    src = (uint8_t*)malloc(src_size);
    dst = (uint8_t*)calloc(dst_size, sizeof(uint8_t));
    lut = (float*)malloc(lut_size);

    for (size_t i = 0; i < iindex_size; i++) {
        _usr_index[i] = rand() % 256;
    }
    for (size_t i = 0; i < src_size; i++) {
        src[i] = rand() % 256;
    }
    for (int i = 0; i < 256; i++) {
        lut[i] = rand() % 512 - 128;
    }
}