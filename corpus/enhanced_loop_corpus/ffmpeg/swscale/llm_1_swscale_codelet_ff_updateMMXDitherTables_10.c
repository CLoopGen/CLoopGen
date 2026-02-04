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
    if (vChrFilterSize <= 0) return;
    int i = 0;
    for (; i < vChrFilterSize - 1; i += 2) {
        *(const void **)&chrMmxFilter[s * i] = chrUSrcPtr[i];
        *(const void **)&chrMmxFilter[s * i + 1] = chrUSrcPtr[i + 1];
        int32_t val = vChrFilter[chrDstY * vChrFilterSize + i] + vChrFilter[chrDstY * vChrFilterSize + i + 1] * (1 << 16);
        chrMmxFilter[s * i + 2] = chrMmxFilter[s * i + 3] = val;
    }
    if (i == vChrFilterSize - 1) {
        *(const void **)&chrMmxFilter[s * i] = chrUSrcPtr[i];
        *(const void **)&chrMmxFilter[s * i + 1] = chrUSrcPtr[i];
        chrMmxFilter[s * i + 2] = chrMmxFilter[s * i + 3] = vChrFilter[chrDstY * vChrFilterSize + i];
    }
}
