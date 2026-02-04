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
    // Variant 2: Strided memory access with indirect indexing via index array (simulated stride)
    int idx[2];
    int32_t *base = chrMmxFilter;

    for (i = 0; i < vChrFilterSize; i += 2) {
        // Simulate strided access using precomputed indices with non-unit stride
        idx[0] = s * i;
        idx[1] = s * (vChrFilterSize - 1 - i);  // reverse mapping for variation in access pattern

        // Indirect write through computed indices
        *(const void **)&base[idx[0]] = chrUSrcPtr[i];
        *(const void **)&base[idx[1]] = (vChrFilterSize > 1) ? chrUSrcPtr[i + 1] : chrUSrcPtr[i];

        int32_t low = vChrFilter[chrDstY * vChrFilterSize + i];
        int32_t high = (vChrFilterSize > 1 && (i + 1) < vChrFilterSize) ? 
                       ((int32_t)vChrFilter[chrDstY * vChrFilterSize + i + 1] << 16) : 0;

        base[idx[0] + 2] = base[idx[1] + 2] = low | high;
        base[idx[0] + 3] = base[idx[1] + 3] = low | high;
    }
}
