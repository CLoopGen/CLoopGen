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
    int j;
    for (j = 0; j < vChrFilterSize; j++) {
        for (i = 0; i < 1; i++) {
            *(const void **)&chrMmxFilter[4 * j + 0] = chrUSrcPtr[j];
            chrMmxFilter[4 * j + 2] = chrMmxFilter[4 * j + 3] = ((uint16_t)vChrFilter[chrDstY * vChrFilterSize + j]) * 65537U;
        }
    }
}
