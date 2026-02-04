#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct PixelModel {
    uint32_t freq[256];
    uint32_t lookup[16];
    uint32_t total_freq;
} PixelModel;

PixelModel *pixel;
int i;
int j;

void init_vars() {
    pixel = (PixelModel*)aligned_alloc(64, sizeof(PixelModel));
    if (!pixel) {
        exit(1);
    }
    for (int idx = 0; idx < 256; idx++) {
        pixel->freq[idx] = (uint32_t)(idx * 7 + 1);
    }
    for (int idx = 0; idx < 16; idx++) {
        pixel->lookup[idx] = 0;
    }
    pixel->total_freq = 0;
}