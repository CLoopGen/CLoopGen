#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int hasAlpha;
extern int16_t *vLumFilter;
extern int32_t *lumMmxFilter;
extern __attribute__((unused)) int32_t *alpMmxFilter;
extern  int vLumFilterSize;
extern int dstY;
extern  int16_t **lumSrcPtr;
extern  int16_t **alpSrcPtr;
extern int i;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < vLumFilterSize; i++) {
    int idx = s * i;
    lumMmxFilter[idx] = (int32_t)(intptr_t)lumSrcPtr[i];
    if (vLumFilterSize > 1 && i + 1 < vLumFilterSize) {
        lumMmxFilter[idx + 1] = (int32_t)(intptr_t)lumSrcPtr[i + 1];
    }
    int filterIdx = dstY * vLumFilterSize + i;
    int32_t val = vLumFilter[filterIdx];
    if (vLumFilterSize > 1 && i + 1 < vLumFilterSize) {
        val += vLumFilter[filterIdx + 1] << 16;
    }
    lumMmxFilter[idx + 2] = lumMmxFilter[idx + 3] = val;
    if (hasAlpha) {
        alpMmxFilter[idx] = (int32_t)(intptr_t)alpSrcPtr[i];
        if (vLumFilterSize > 1 && i + 1 < vLumFilterSize) {
            alpMmxFilter[idx + 1] = (int32_t)(intptr_t)alpSrcPtr[i + 1];
        }
        alpMmxFilter[idx + 2] = alpMmxFilter[idx + 3] = val;
    }
}
}
