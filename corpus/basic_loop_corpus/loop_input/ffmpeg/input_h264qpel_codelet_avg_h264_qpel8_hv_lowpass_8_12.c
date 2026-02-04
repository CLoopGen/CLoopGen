#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(uint8_t))

int16_t *tmp;
int tmpStride;
int srcStride;
int h;
int pad;
int i;
uint8_t *src;

void init_vars() {
    const int width = 16;
    h = 1000;
    pad = 10;
    srcStride = width;
    tmpStride = width;

    src = aligned_alloc(32, (h + 5) * srcStride * sizeof(uint8_t));
    tmp = aligned_alloc(32, (h + 5) * tmpStride * sizeof(int16_t));

    if (!src || !tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < (h + 5) * srcStride; i++) {
        src[i] = rand() & 0xFF;
    }

    for (int i = 0; i < (h + 5) * tmpStride; i++) {
        tmp[i] = 0;
    }
}