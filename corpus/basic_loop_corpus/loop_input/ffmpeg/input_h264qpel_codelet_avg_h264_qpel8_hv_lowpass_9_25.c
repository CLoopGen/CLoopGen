#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64

static size_t total_data_size = DATA_SIZE_MB * 1024ULL * 1024ULL;

int16_t *tmp;
uint16_t *src;
int tmpStride;
int srcStride;
int h;
int pad;
int i;

void init_vars() {
    const int width = 11; 
    const int height = (total_data_size / sizeof(uint16_t)) / width;
    
    h = height - 5;
    if (h <= 0) {
        h = 1;
    }

    srcStride = width;
    tmpStride = 8;

    pad = 10;

    src = aligned_alloc(32, (size_t)(height + 2) * srcStride * sizeof(uint16_t));
    tmp = aligned_alloc(32, (size_t)(h + 5) * tmpStride * sizeof(int16_t));

    for (int y = 0; y < height + 2; y++) {
        for (int x = 0; x < width; x++) {
            src[y * srcStride + x] = (uint16_t)(x * y % 257);
        }
    }

    for (int y = 0; y < h + 5; y++) {
        for (int x = 0; x < tmpStride; x++) {
            tmp[y * tmpStride + x] = 0;
        }
    }
}