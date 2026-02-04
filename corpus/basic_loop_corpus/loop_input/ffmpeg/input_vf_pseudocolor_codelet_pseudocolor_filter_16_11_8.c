#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int max = 65535;
int width = 1024;
int height = 256;
ptrdiff_t ilinesize = 2048;
ptrdiff_t slinesize = 1024;
ptrdiff_t dlinesize = 1024;

float *lut;
uint16_t *_usr_index;
uint16_t *src;
uint16_t *dst;
int x;
int y;

#define index _usr_index

void init_vars() {
    const size_t total_data_size = (size_t)width * height * sizeof(uint16_t) * 4 + 65536 * sizeof(float);
    
    lut = aligned_alloc(32, 65536 * sizeof(float));
    _usr_index = aligned_alloc(32, ilinesize * height * 2 * sizeof(uint16_t));
    src = aligned_alloc(32, slinesize * height * sizeof(uint16_t));
    dst = aligned_alloc(32, dlinesize * height * sizeof(uint16_t));

    for (int i = 0; i < 65536; i++) {
        lut[i] = (float)(i * 0.75);
    }

    for (int y_idx = 0; y_idx < height * 2; y_idx++) {
        for (int x_idx = 0; x_idx < width * 2; x_idx++) {
            index[y_idx * ilinesize + x_idx] = rand() % 65536;
        }
    }

    for (int y_idx = 0; y_idx < height; y_idx++) {
        for (int x_idx = 0; x_idx < width; x_idx++) {
            src[y_idx * slinesize + x_idx] = rand() % 65536;
            dst[y_idx * dlinesize + x_idx] = 0;
        }
    }

    max = 65535;
    width = 1024;
    height = 256;
    ilinesize = 2048;
    slinesize = 1024;
    dlinesize = 1024;
}