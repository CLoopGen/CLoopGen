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
    int16_t *tempPtr = NULL;
    uint32_t tempVal = 0;
    for (i = 0; i < vChrFilterSize; i++) {
        tempPtr = chrUSrcPtr[i];
        *(const void **)&chrMmxFilter[4 * i + 0] = tempPtr;
        tempVal = ((uint16_t)vChrFilter[chrDstY * vChrFilterSize + i]) * 65537U;
        chrMmxFilter[4 * i + 2] = tempVal;
        chrMmxFilter[4 * i + 3] = tempVal;
    }
}
