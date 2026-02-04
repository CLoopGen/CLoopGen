#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(uint16_t))

int16_t *tmp;
int tmpStride;
int srcStride;
int h;
int pad;
int i;
uint16_t *src;

void init_vars() {
    h = 1000;
    pad = 10;
    srcStride = 16;
    tmpStride = 16;

    src = aligned_alloc(32, sizeof(uint16_t) * (TOTAL_ELEMENTS));
    tmp = aligned_alloc(32, sizeof(int16_t) * (h + 5) * tmpStride);

    for (size_t i = 0; i < TOTAL_ELEMENTS; ++i) {
        src[i] = rand() & 0xFFFF;
    }

    for (int i = 0; i < (h + 5); ++i) {
        int16_t* tmp_row = tmp + i * tmpStride;
        for (int j = 0; j < 8; ++j) {
            tmp_row[j] = 0;
        }
    }
}