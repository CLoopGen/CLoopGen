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



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic and unrolled stride simulation
    int16_t **srcPtr = chrUSrcPtr;
    int32_t *filter = chrMmxFilter + s * 0;
    const int offset = chrDstY * vChrFilterSize;
    const int16_t *vFilter = vChrFilter + offset;
    
    for (i = 0; i < vChrFilterSize; i += 2) {
        // Use direct pointer arithmetic for consecutive access pattern
        *(const void **)(filter + s * i + 0) = srcPtr[i];
        *(const void **)(filter + s * i + 1) = (vChrFilterSize > 1) ? srcPtr[i + 1] : srcPtr[i];

        int32_t val = vFilter[i];
        if (vChrFilterSize > 1 && (i + 1) < vChrFilterSize) {
            val |= (int32_t)vFilter[i + 1] << 16;
        }
        filter[s * i + 2] = filter[s * i + 3] = val;
    }
}
