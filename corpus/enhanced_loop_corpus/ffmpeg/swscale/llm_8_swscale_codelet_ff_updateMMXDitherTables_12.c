#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *vChrFilter;
extern int32_t *chrMmxFilter;
extern  int vChrFilterSize;
extern  int chrDstY;
extern  int16_t **chrUSrcPtr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < vChrFilterSize; i += 2) {
        if (i + 1 < vChrFilterSize) {
            *(const void **)&chrMmxFilter[4 * i + 0] = chrUSrcPtr[i];
            *(const void **)&chrMmxFilter[4 * (i + 1) + 0] = chrUSrcPtr[i + 1];
            uint32_t val1 = ((uint16_t)vChrFilter[chrDstY * vChrFilterSize + i]) * 65537U;
            uint32_t val2 = ((uint16_t)vChrFilter[chrDstY * vChrFilterSize + i + 1]) * 65537U;
            chrMmxFilter[4 * i + 2] = val1;
            chrMmxFilter[4 * i + 3] = val1;
            chrMmxFilter[4 * (i + 1) + 2] = val2;
            chrMmxFilter[4 * (i + 1) + 3] = val2;
        } else {
            *(const void **)&chrMmxFilter[4 * i + 0] = chrUSrcPtr[i];
            chrMmxFilter[4 * i + 2] = chrMmxFilter[4 * i + 3] = ((uint16_t)vChrFilter[chrDstY * vChrFilterSize + i]) * 65537U;
        }
    }
}
