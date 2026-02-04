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
int limit = (vChrFilterSize + 3) / 4;
for (i = 0; i < limit; i++) {
    int base_in = i * 4;
    int base_out = s * base_in;

    if (base_in < vChrFilterSize) {
        *(const void **)&chrMmxFilter[base_out] = chrUSrcPtr[base_in];
        chrMmxFilter[base_out + 2] = vChrFilter[chrDstY * vChrFilterSize + base_in];
    }

    if (base_in + 1 < vChrFilterSize) {
        *(const void **)&chrMmxFilter[base_out + 1] = chrUSrcPtr[base_in + 1];
        chrMmxFilter[base_out + 2] |= vChrFilter[chrDstY * vChrFilterSize + base_in + 1] << 16;
        chrMmxFilter[base_out + 3] = chrMmxFilter[base_out + 2];
    } else {
        chrMmxFilter[base_out + 1] = chrMmxFilter[base_out];
        chrMmxFilter[base_out + 2] = chrMmxFilter[base_out + 3] = vChrFilter[chrDstY * vChrFilterSize + base_in];
    }

    if (base_in + 2 < vChrFilterSize) {
        *(const void **)&chrMmxFilter[base_out + 4] = chrUSrcPtr[base_in + 2];
        chrMmxFilter[base_out + 6] = vChrFilter[chrDstY * vChrFilterSize + base_in + 2];
    }

    if (base_in + 3 < vChrFilterSize) {
        *(const void **)&chrMmxFilter[base_out + 5] = chrUSrcPtr[base_in + 3];
        chrMmxFilter[base_out + 6] |= vChrFilter[chrDstY * vChrFilterSize + base_in + 3] << 16;
        chrMmxFilter[base_out + 7] = chrMmxFilter[base_out + 6];
    } else if (base_in + 2 < vChrFilterSize) {
        chrMmxFilter[base_out + 5] = chrMmxFilter[base_out + 4];
        chrMmxFilter[base_out + 6] = chrMmxFilter[base_out + 7] = vChrFilter[chrDstY * vChrFilterSize + base_in + 2];
    }
}
}
