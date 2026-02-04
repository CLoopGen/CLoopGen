#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int hasAlpha = 1;

int vLumFilterSize = 65536; // ~1MB of data: 65536 * (2 + 4 + 4) bytes per element in worst case

int dstY = 0;

int i = 0;

int16_t *vLumFilter;
int32_t *lumMmxFilter;
int32_t *alpMmxFilter;

int16_t **lumSrcPtr;
int16_t **alpSrcPtr;

void init_vars() {
    vLumFilter = aligned_alloc(32, sizeof(int16_t) * vLumFilterSize);
    lumMmxFilter = aligned_alloc(32, sizeof(int32_t) * 4 * vLumFilterSize);
    alpMmxFilter = aligned_alloc(32, sizeof(int32_t) * 4 * vLumFilterSize);
    lumSrcPtr = aligned_alloc(32, sizeof(int16_t*) * vLumFilterSize);
    alpSrcPtr = aligned_alloc(32, sizeof(int16_t*) * vLumFilterSize);

    for (int i = 0; i < vLumFilterSize; i++) {
        vLumFilter[i] = rand() % 32768;
        lumSrcPtr[i] = aligned_alloc(32, sizeof(int16_t) * 2);
        lumSrcPtr[i][0] = rand();
        lumSrcPtr[i][1] = rand();
        alpSrcPtr[i] = aligned_alloc(32, sizeof(int16_t) * 2);
        alpSrcPtr[i][0] = rand();
        alpSrcPtr[i][1] = rand();
    }
}