#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_ARRAY (DATA_SIZE_MB * 1024 * 1024 / sizeof(int16_t) / 2)
#define NUM_ARRAYS 2

int16_t **lumSrcPtr;
int16_t **tmpY;
int i;
int end;

void init_vars() {
    lumSrcPtr = (int16_t**)calloc(NUM_ARRAYS, sizeof(int16_t*));
    tmpY = (int16_t**)calloc(NUM_ARRAYS, sizeof(int16_t*));

    for (int idx = 0; idx < NUM_ARRAYS; idx++) {
        lumSrcPtr[idx] = (int16_t*)aligned_alloc(32, ELEMENTS_PER_ARRAY * sizeof(int16_t));
        tmpY[idx] = (int16_t*)aligned_alloc(32, ELEMENTS_PER_ARRAY * sizeof(int16_t));

        for (int j = 0; j < ELEMENTS_PER_ARRAY; j++) {
            lumSrcPtr[idx][j] = (int16_t)(j & 0xFFFF);
            tmpY[idx][j] = 0;
        }
    }

    i = 0;
    end = NUM_ARRAYS;
}