#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(int16_t))

int vChrFilterSize = 16;
int chrDstY = 4;
int i;
int s = 2;

int32_t *chrMmxFilter;
int16_t **chrUSrcPtr;
int16_t *vChrFilter;

void init_vars() {
    vChrFilterSize = 16;
    chrDstY = 4;
    s = 2;
    i = 0;

    chrMmxFilter = aligned_alloc(16, sizeof(int32_t) * vChrFilterSize * s + 8);
    
    vChrFilter = malloc(sizeof(int16_t) * TOTAL_ELEMENTS);
    chrUSrcPtr = malloc(sizeof(int16_t*) * vChrFilterSize);

    for (int idx = 0; idx < vChrFilterSize; ++idx) {
        chrUSrcPtr[idx] = &vChrFilter[idx % vChrFilterSize + chrDstY * vChrFilterSize];
    }

    for (int idx = 0; idx < TOTAL_ELEMENTS; ++idx) {
        vChrFilter[idx] = rand() % 65536 - 32768;
    }
}