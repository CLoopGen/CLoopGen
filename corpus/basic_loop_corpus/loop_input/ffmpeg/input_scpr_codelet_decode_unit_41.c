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
uint32_t totfr;
int i;

void init_vars() {
    pixel = (PixelModel*)aligned_alloc(64, sizeof(PixelModel));
    if (!pixel) exit(1);

    for (int j = 0; j < 256; j++) {
        pixel->freq[j] = (j + 1) * 1000;
    }
    for (int j = 0; j < 16; j++) {
        pixel->lookup[j] = j * 100;
    }
    pixel->total_freq = 0;
    totfr = 0;
    i = 0;
}