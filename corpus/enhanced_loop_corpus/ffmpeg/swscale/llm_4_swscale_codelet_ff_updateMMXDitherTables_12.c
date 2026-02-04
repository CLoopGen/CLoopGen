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
        if ((vChrFilter[chrDstY * vChrFilterSize + i] & 0x8000) == 0) {
            *(const void **)&chrMmxFilter[4 * i + 0] = chrUSrcPtr[i];
            chrMmxFilter[4 * i + 2] = chrMmxFilter[4 * i + 3] = ((uint16_t)vChrFilter[chrDstY * vChrFilterSize + i]) * 65537U;
        }
    }
}
