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
    int32_t tempVal[vLumFilterSize > 16 ? vLumFilterSize : 16]; 
    for (i = 0; i < vLumFilterSize; i++) {
        int idx = dstY * vLumFilterSize + i;
        tempVal[i] = ((uint16_t)vLumFilter[idx]) * 65537U;
        *(const void **)&lumMmxFilter[4 * i + 0] = lumSrcPtr[i];
    }
    for (i = 0; i < vLumFilterSize; i++) {
        lumMmxFilter[4 * i + 2] = tempVal[i];
        lumMmxFilter[4 * i + 3] = tempVal[i];
        if (hasAlpha) {
            *(const void **)&alpMmxFilter[4 * i + 0] = alpSrcPtr[i];
            alpMmxFilter[4 * i + 2] = tempVal[i];
            alpMmxFilter[4 * i + 3] = tempVal[i];
        }
    }
}
