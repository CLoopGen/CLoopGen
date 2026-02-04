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
int step = (vLumFilterSize > 4) ? 4 : 2;
for (i = 0; i < vLumFilterSize; i += step) {
    int base_s = s * i;
    int next_i = i + (vLumFilterSize > 1 ? 1 : 0);
    int next_s = s * next_i;

    *(const void **)&lumMmxFilter[base_s] = lumSrcPtr[i];
    if (vLumFilterSize > 1 && next_i < vLumFilterSize) {
        *(const void **)&lumMmxFilter[next_s] = lumSrcPtr[next_i];
    }

    int32_t low_val = vLumFilter[dstY * vLumFilterSize + i];
    int32_t high_val = (vLumFilterSize > 1 && next_i < vLumFilterSize) ? vLumFilter[dstY * vLumFilterSize + next_i] : 0;
    int32_t combined = low_val | (high_val << 16);

    lumMmxFilter[base_s + 2] = combined;
    lumMmxFilter[base_s + 3] = combined;

    if (hasAlpha) {
        *(const void **)&alpMmxFilter[base_s] = alpSrcPtr[i];
        if (vLumFilterSize > 1 && next_i < vLumFilterSize) {
            *(const void **)&alpMmxFilter[next_s] = alpSrcPtr[next_i];
        }
        alpMmxFilter[base_s + 2] = combined;
        alpMmxFilter[base_s + 3] = combined;
    }

    // Unrolled filler for larger step to increase compute intensity
    for (int j = 1; j < step && i + j < vLumFilterSize; j++) {
        int idx = s * (i + j);
        lumMmxFilter[idx + 2] = lumMmxFilter[idx + 3] = vLumFilter[dstY * vLumFilterSize + i + j];
        if (hasAlpha) {
            alpMmxFilter[idx + 2] = alpMmxFilter[idx + 3] = lumMmxFilter[idx + 2];
        }
    }
}
}
