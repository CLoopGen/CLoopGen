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
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < vChrFilterSize; i += 2) {
        if (vChrFilterSize <= 1 && i + 1 >= vChrFilterSize) continue;
        *(const void **)&chrMmxFilter[s * i] = chrUSrcPtr[i];
        *(const void **)&chrMmxFilter[s * i + 1] = chrUSrcPtr[i + 1];
        int32_t val = vChrFilter[chrDstY * vChrFilterSize + i];
        if (vChrFilterSize > 1) {
            val += vChrFilter[chrDstY * vChrFilterSize + i + 1] << 16;
        }
        chrMmxFilter[s * i + 2] = chrMmxFilter[s * i + 3] = val;
    }
}
