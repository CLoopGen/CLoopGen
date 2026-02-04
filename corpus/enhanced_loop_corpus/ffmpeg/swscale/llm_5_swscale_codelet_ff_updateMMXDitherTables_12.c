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
    for (i = 0; i < vChrFilterSize; i++) {
        const int offset = chrDstY * vChrFilterSize + i;
        const uint16_t filterVal = (uint16_t)vChrFilter[offset];
        const int32_t expandedVal = filterVal * 65537U;

        *(const void **)&chrMmxFilter[4 * i + 0] = chrUSrcPtr[i];

        if (filterVal != 0) {
            chrMmxFilter[4 * i + 2] = expandedVal;
            chrMmxFilter[4 * i + 3] = expandedVal;
        } else {
            chrMmxFilter[4 * i + 2] = 0;
            chrMmxFilter[4 * i + 3] = 0;
        }
    }
}
