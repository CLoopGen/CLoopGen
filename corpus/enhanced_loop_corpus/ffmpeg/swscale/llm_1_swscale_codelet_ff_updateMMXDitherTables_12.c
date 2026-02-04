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
    int outer_i = 0;
    int inner_i;
    if (vChrFilterSize > 0) {
        for (inner_i = 0; inner_i < vChrFilterSize; inner_i++) {
            i = outer_i + inner_i;
            *(const void **)&chrMmxFilter[4 * i + 0] = chrUSrcPtr[i];
            chrMmxFilter[4 * i + 2] = chrMmxFilter[4 * i + 3] = ((uint16_t)vChrFilter[chrDstY * vChrFilterSize + i]) * 65537U;
        }
    }
}
