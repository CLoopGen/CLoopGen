#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(int16_t))
#define TOTAL_ELEMENTS (DATA_SIZE_MB * ELEMENTS_PER_MB)

int16_t **chrUSrcPtr;
int16_t **tmpU;
int i = 0;
int end = TOTAL_ELEMENTS;

void init_vars() {
    chrUSrcPtr = (int16_t**)calloc(TOTAL_ELEMENTS, sizeof(int16_t*));
    tmpU = (int16_t**)calloc(TOTAL_ELEMENTS, sizeof(int16_t*));

    for (int idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        int16_t* row = (int16_t*)malloc(16 * sizeof(int16_t));
        for (int j = 0; j < 16; j++) {
            row[j] = (int16_t)(idx + j);
        }
        chrUSrcPtr[idx] = row;
        tmpU[idx] = NULL;
    }

    i = 0;
    end = TOTAL_ELEMENTS;
}