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
    int offset;
    for (i = 0; i < vLumFilterSize; i++) {
        offset = 4 * i;
        *(const void **)&lumMmxFilter[offset + 0] = lumSrcPtr[i];
        int32_t val = ((uint16_t)vLumFilter[dstY * vLumFilterSize + i]) * 65537U;
        lumMmxFilter[offset + 2] = val;
        lumMmxFilter[offset + 3] = val;
        if (hasAlpha) {
            *(const void **)&alpMmxFilter[offset + 0] = alpSrcPtr[i];
            alpMmxFilter[offset + 2] = val;
            alpMmxFilter[offset + 3] = val;
        }
    }
}
