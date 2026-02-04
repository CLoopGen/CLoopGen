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
    // Variant 2: Strided memory access - reverse striding through chrMmxFilter and indirect src access
    int j;
    for (j = 0; j < vChrFilterSize; j++) {
        int rev_i = vChrFilterSize - 1 - j;  // Reverse index for strided access
        int stride_offset = 4 * rev_i;

        // Indirect access to source via reversed index
        int16_t *indirectSrc = chrUSrcPtr[rev_i];
        *(const void **)&chrMmxFilter[stride_offset + 0] = indirectSrc;

        // Apply filter scaling with original filter but accessed in reverse order
        uint32_t val = ((uint16_t)vChrFilter[chrDstY * vChrFilterSize + rev_i]) * 65537U;
        chrMmxFilter[stride_offset + 2] = val;
        chrMmxFilter[stride_offset + 3] = val;
    }
}
