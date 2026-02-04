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



void loop() {
    // Variant 1: Consecutive memory access with precomputed indices and coalesced pointer arithmetic
    int idx = dstY * vLumFilterSize;
    int step = s * 2;
    for (i = 0; i < vLumFilterSize; i += 2) {
        int mmxIdx = s * i;
        int srcIdx = i;
        int nextSrcIdx = i + (vLumFilterSize > 1);

        // Coalesce lumSrcPtr accesses into sequential pattern
        ((const void **)lumMmxFilter)[mmxIdx / sizeof(void*)] = lumSrcPtr[srcIdx];
        ((const void **)lumMmxFilter)[(mmxIdx + 4) / sizeof(void*)] = lumSrcPtr[nextSrcIdx];

        int32_t val0 = vLumFilter[idx + srcIdx];
        int32_t val1 = (vLumFilterSize > 1) ? vLumFilter[idx + srcIdx + 1] : 0;
        int32_t combined = val0 | (val1 << 16);
        lumMmxFilter[mmxIdx / 4 + 2] = combined;
        lumMmxFilter[mmxIdx / 4 + 3] = combined;

        if (hasAlpha) {
            ((const void **)alpMmxFilter)[mmxIdx / sizeof(void*)] = alpSrcPtr[srcIdx];
            ((const void **)alpMmxFilter)[(mmxIdx + 4) / sizeof(void*)] = alpSrcPtr[nextSrcIdx];
            alpMmxFilter[mmxIdx / 4 + 2] = combined;
            alpMmxFilter[mmxIdx / 4 + 3] = combined;
        }
    }
}
