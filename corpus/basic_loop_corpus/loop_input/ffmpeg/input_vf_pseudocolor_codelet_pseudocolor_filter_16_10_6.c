#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
    const size_t total_elements = (size_t)width * height;
    const size_t lut_size = 65536 * sizeof(float);

    lut = (float *)aligned_alloc(32, lut_size);
    _usr_index = (uint16_t *)aligned_alloc(32, total_elements * 2 * sizeof(uint16_t));
    src = (uint16_t *)aligned_alloc(32, total_elements * sizeof(uint16_t));
    dst = (uint16_t *)aligned_alloc(32, total_elements * sizeof(uint16_t));

    for (size_t i = 0; i < 65536; i++) {
        lut[i] = (float)(i % (max + 1));
    }

    for (size_t i = 0; i < total_elements * 2; i++) {
        _usr_index[i] = (uint16_t)(i % 65536);
    }

    for (size_t i = 0; i < total_elements; i++) {
        src[i] = (uint16_t)(i % 65536);
        dst[i] = 0;
    }
}