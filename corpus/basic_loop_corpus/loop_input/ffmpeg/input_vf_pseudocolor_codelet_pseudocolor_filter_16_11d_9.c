#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int max = 65535;
int width = 1024;
int height = 1024;
ptrdiff_t ilinesize = 512;
ptrdiff_t slinesize = 1024;
ptrdiff_t dlinesize = 1024;

float *lut;
uint16_t *_usr_index;
uint16_t *src;
uint16_t *dst;
int x;
int y;

void init_vars() {
    const size_t input_size = width * height;
    const size_t index_size = (height / 2) * (width / 2);
    const size_t lut_size = 65536;

    lut = aligned_alloc(32, lut_size * sizeof(float));
    _usr_index = aligned_alloc(32, index_size * sizeof(uint16_t));
    src = aligned_alloc(32, input_size * sizeof(uint16_t));
    dst = aligned_alloc(32, input_size * sizeof(uint16_t));

    for (size_t i = 0; i < lut_size; i++) {
        lut[i] = (float)(rand() % (max + 1));
    }

    for (size_t i = 0; i < index_size; i++) {
        _usr_index[i] = rand() % lut_size;
    }

    for (size_t i = 0; i < input_size; i++) {
        src[i] = rand() % (max + 1);
        dst[i] = 0;
    }
}