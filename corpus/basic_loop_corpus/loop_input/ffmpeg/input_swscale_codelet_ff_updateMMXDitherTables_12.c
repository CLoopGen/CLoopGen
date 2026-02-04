#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *vChrFilter;
int32_t *chrMmxFilter;
int vChrFilterSize;
int chrDstY;
int16_t **chrUSrcPtr;
int i;

void init_vars() {
    vChrFilterSize = 65536;
    chrDstY = 1;

    vChrFilter = (int16_t*)aligned_alloc(16, sizeof(int16_t) * vChrFilterSize * (chrDstY + 1));
    chrMmxFilter = (int32_t*)aligned_alloc(16, sizeof(int32_t) * 4 * vChrFilterSize);
    chrUSrcPtr = (int16_t**)aligned_alloc(16, sizeof(int16_t*) * vChrFilterSize);

    for (int idx = 0; idx < vChrFilterSize * (chrDstY + 1); idx++) {
        vChrFilter[idx] = (int16_t)(idx % 32768);
    }

    for (int idx = 0; idx < vChrFilterSize; idx++) {
        int16_t *ptr = (int16_t*)aligned_alloc(16, sizeof(int16_t) * 16);
        for (int j = 0; j < 16; j++) {
            ptr[j] = (int16_t)((idx + j) % 32768);
        }
        chrUSrcPtr[idx] = ptr;
    }

    for (int idx = 0; idx < 4 * vChrFilterSize; idx++) {
        chrMmxFilter[idx] = 0;
    }
}