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



void loop() {
    // Variant 1: Consecutive memory access with local accumulation and write-back
    int j;
    for (j = 0; j < vChrFilterSize; j++) {
        int idx = 4 * j;
        int filterIdx = chrDstY * vChrFilterSize + j;
        int16_t **srcPtr = &chrUSrcPtr[j];

        // Store pointer in aligned chunk
        *(const void **)&chrMmxFilter[idx + 0] = *srcPtr;
        // Replicate filter value across two adjacent slots using consecutive indexing
        uint32_t scaledVal = ((uint16_t)vChrFilter[filterIdx]) * 65537U;
        chrMmxFilter[idx + 1] = scaledVal;  // Inserted extra use of consecutive access
        chrMmxFilter[idx + 2] = scaledVal;
        chrMmxFilter[idx + 3] = scaledVal;
    }
}
