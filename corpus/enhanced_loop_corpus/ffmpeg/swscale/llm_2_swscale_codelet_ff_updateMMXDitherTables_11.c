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

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic and loop unrolling by 2
    int i;
    int16_t **lumSrc = lumSrcPtr;
    int16_t **alpSrc = alpSrcPtr;
    int16_t *vLum = vLumFilter + dstY * vLumFilterSize;
    int32_t *lumMmx = lumMmxFilter;
    int32_t *alpMmx = alpMmxFilter;

    for (i = 0; i <= vLumFilterSize - 2; i += 2) {
        *(const void **)&lumMmx[4 * i + 0] = lumSrc[i];
        *(const void **)&lumMmx[4 * i + 4] = lumSrc[i + 1];
        lumMmx[4 * i + 2] = lumMmx[4 * i + 3] = ((uint16_t)vLum[i]) * 65537U;
        lumMmx[4 * i + 6] = lumMmx[4 * i + 7] = ((uint16_t)vLum[i + 1]) * 65537U;

        if (hasAlpha) {
            *(const void **)&alpMmx[4 * i + 0] = alpSrc[i];
            *(const void **)&alpMmx[4 * i + 4] = alpSrc[i + 1];
            alpMmx[4 * i + 2] = alpMmx[4 * i + 3] = lumMmx[4 * i + 2];
            alpMmx[4 * i + 6] = alpMmx[4 * i + 7] = lumMmx[4 * i + 6];
        }
    }

    // Handle remaining element if vLumFilterSize is odd
    if (i < vLumFilterSize) {
        *(const void **)&lumMmx[4 * i + 0] = lumSrc[i];
        lumMmx[4 * i + 2] = lumMmx[4 * i + 3] = ((uint16_t)vLum[i]) * 65537U;
        if (hasAlpha) {
            *(const void **)&alpMmx[4 * i + 0] = alpSrc[i];
            alpMmx[4 * i + 2] = alpMmx[4 * i + 3] = lumMmx[4 * i + 2];
        }
    }
}
