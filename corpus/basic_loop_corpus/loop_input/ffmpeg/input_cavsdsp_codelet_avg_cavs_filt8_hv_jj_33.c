#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define TMP_SIZE (20 * 8)
#define DST_HEIGHT 8
#define DATA_SIZE_MB 64

void init_vars() {
    const size_t total_data_size = (size_t)DATA_SIZE_MB * 1024 * 1024;
    w = (int)((total_data_size / sizeof(int16_t)) / TMP_SIZE);
    if (w == 0) w = 1;

    tmp = aligned_alloc(32, (TMP_SIZE + w) * sizeof(int16_t));
    dstStride = 1;
    dst = malloc(w * DST_HEIGHT * sizeof(uint8_t));
    cm = malloc(512 * sizeof(uint8_t));

    for (int j = 0; j < TMP_SIZE + w; j++) {
        tmp[j] = rand() % 256 - 128;
    }

    for (int j = 0; j < w * DST_HEIGHT; j++) {
        dst[j] = rand() % 256;
    }

    for (int j = 0; j < 512; j++) {
        cm[j] = rand() % 256;
    }
}