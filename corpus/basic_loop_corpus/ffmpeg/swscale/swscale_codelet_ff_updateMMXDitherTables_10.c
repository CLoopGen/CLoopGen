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
    *(const void **)&chrMmxFilter[s * i] = chrUSrcPtr[i];
    *(const void **)&chrMmxFilter[s * i + 4 / 4] = chrUSrcPtr[i + (vChrFilterSize > 1)];
    chrMmxFilter[s * i + 8 / 4] = chrMmxFilter[s * i + 8 / 4 + 1] = vChrFilter[chrDstY * vChrFilterSize + i] + (vChrFilterSize > 1 ? vChrFilter[chrDstY * vChrFilterSize + i + 1] * (1 << 16) : 0);
}

}
