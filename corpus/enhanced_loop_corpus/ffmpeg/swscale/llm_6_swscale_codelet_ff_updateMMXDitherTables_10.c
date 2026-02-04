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
        int32_t temp1 = (intptr_t)chrUSrcPtr[i];
        int32_t temp2 = (vChrFilterSize > 1) ? (intptr_t)chrUSrcPtr[i + 1] : temp1;

        chrMmxFilter[s * i] = temp1;
        chrMmxFilter[s * i + 1] = temp2;

        int32_t coeff = vChrFilter[chrDstY * vChrFilterSize + i];
        if (vChrFilterSize > 1 && i + 1 < vChrFilterSize) {
            coeff += vChrFilter[chrDstY * vChrFilterSize + i + 1] << 16;
        }

        chrMmxFilter[s * i + 2] = coeff;
        chrMmxFilter[s * i + 3] = coeff;
    }
}
