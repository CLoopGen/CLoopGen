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



void loop(){
    for (i = 0; i < vLumFilterSize && hasAlpha; i += 2) {
        int idx1 = 4 * i;
        int idx2 = 4 * (i + 1);
        if (i + 1 < vLumFilterSize) {
            *(const void **)&lumMmxFilter[idx1 + 0] = lumSrcPtr[i];
            *(const void **)&lumMmxFilter[idx2 + 0] = lumSrcPtr[i + 1];
            uint32_t val1 = ((uint16_t)vLumFilter[dstY * vLumFilterSize + i]) * 65537U;
            uint32_t val2 = ((uint16_t)vLumFilter[dstY * vLumFilterSize + i + 1]) * 65537U;
            lumMmxFilter[idx1 + 2] = lumMmxFilter[idx1 + 3] = val1;
            lumMmxFilter[idx2 + 2] = lumMmxFilter[idx2 + 3] = val2;
            *(const void **)&alpMmxFilter[idx1 + 0] = alpSrcPtr[i];
            *(const void **)&alpMmxFilter[idx2 + 0] = alpSrcPtr[i + 1];
            alpMmxFilter[idx1 + 2] = alpMmxFilter[idx1 + 3] = val1;
            alpMmxFilter[idx2 + 2] = alpMmxFilter[idx2 + 3] = val2;
        } else {
            *(const void **)&lumMmxFilter[idx1 + 0] = lumSrcPtr[i];
            uint32_t val1 = ((uint16_t)vLumFilter[dstY * vLumFilterSize + i]) * 65537U;
            lumMmxFilter[idx1 + 2] = lumMmxFilter[idx1 + 3] = val1;
            *(const void **)&alpMmxFilter[idx1 + 0] = alpSrcPtr[i];
            alpMmxFilter[idx1 + 2] = alpMmxFilter[idx1 + 3] = val1;
        }
    }
}
