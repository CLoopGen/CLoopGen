#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t **lumSrcPtr;
int16_t **tmpY;
int neg;
int i;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(int16_t))
#define TOTAL_ELEMENTS (DATA_SIZE_MB * ELEMENTS_PER_MB)
#define NUM_ROWS (TOTAL_ELEMENTS / 256)

void init_vars() {
    neg = NUM_ROWS;

    lumSrcPtr = (int16_t**)calloc(neg, sizeof(int16_t*));
    tmpY = (int16_t**)calloc(neg, sizeof(int16_t*));

    for (int idx = 0; idx < neg; idx++) {
        lumSrcPtr[idx] = (int16_t*)calloc(256, sizeof(int16_t));
        tmpY[idx] = (int16_t*)calloc(256, sizeof(int16_t));
    }
}