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
    int limit = vChrFilterSize & ~1; // Ensure even bound to avoid out-of-bounds
    for (i = 0; i < limit; ++i) {
        int j = i << 1; // Convert to step of 2 indexing via inner scaling
        *(const void **)&chrMmxFilter[s * j] = chrUSrcPtr[j];
        if (vChrFilterSize > 1) {
            *(const void **)&chrMmxFilter[s * j + 1] = chrUSrcPtr[j + 1];
        } else {
            *(const void **)&chrMmxFilter[s * j + 1] = chrUSrcPtr[j]; // Duplicate if size == 1
        }
        int32_t low = vChrFilter[chrDstY * vChrFilterSize + j];
        int32_t high = (vChrFilterSize > 1) ? (int32_t)vChrFilter[chrDstY * vChrFilterSize + j + 1] << 16 : 0;
        int32_t combined = low | high;
        chrMmxFilter[s * j + 2] = combined;
        chrMmxFilter[s * j + 3] = combined;
        ++i; // Simulate i += 2 in original by incrementing twice
    }
}
