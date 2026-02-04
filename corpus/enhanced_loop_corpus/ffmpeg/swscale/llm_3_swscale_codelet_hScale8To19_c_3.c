#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dstW;
extern  uint8_t *src;
extern  int16_t *filter;
extern  int32_t *filterPos;
extern int filterSize;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dstW; i++) {
        int j;
        int val = 0;
        // Change to indirect and non-consecutive access: shuffle access pattern via index remapping
        int baseFilterIdx = filterSize * i;
        for (j = 0; j < filterSize; j++) {
            // Access source with a shuffled offset pattern (e.g., even-odd interleaved)
            int permuted_j = (j % 2 == 0) ? j : filterSize - ((j + 1) / 2); // Example permutation
            if (permuted_j >= filterSize) continue;
            int srcPos = filterPos[i];
            val += ((int)src[srcPos + permuted_j]) * filter[baseFilterIdx + permuted_j];
        }
        dst[i] = ((val >> 3) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val >> 3));
    }
}
