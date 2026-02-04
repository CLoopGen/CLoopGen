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
    // Variant 2: Strided memory access with reverse iteration and stride of 4
    int i;
    const int stride = 4;
    int limit = (vLumFilterSize + stride - 1) / stride;

    for (i = 0; i < limit; i++) {
        int idx = vLumFilterSize - 1 - (i * stride);  // Reverse strided index

        // Process up to 4 elements per iteration in reverse order
        for (int j = 0; j < stride && idx - j >= 0; j++) {
            int k = idx - j;  // Actual index in original arrays
            int32_t val = ((uint16_t)vLumFilter[dstY * vLumFilterSize + k]) * 65537U;

            *(const void **)&lumMmxFilter[4 * k + 0] = lumSrcPtr[k];
            lumMmxFilter[4 * k + 2] = lumMmxFilter[4 * k + 3] = val;

            if (hasAlpha) {
                *(const void **)&alpMmxFilter[4 * k + 0] = alpSrcPtr[k];
                alpMmxFilter[4 * k + 2] = alpMmxFilter[4 * k + 3] = val;
            }
        }
    }
}
