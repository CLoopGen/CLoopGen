#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int dstW;
extern  uint8_t *src;
extern  int16_t *filter;
extern  int32_t *filterPos;
extern int filterSize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j, k;
    // Introduce an outer blocking loop (tiling) to increase nesting depth
    int block_size = 16;
    for (k = 0; k < dstW; k += block_size) {
        for (i = k; i < dstW && i < k + block_size; i++) {
            int srcPos = filterPos[i];
            int val = 0;
            // Inner computation remains the same but now nested within a blocked outer structure
            for (j = 0; j < filterSize; j++) {
                val += ((int)src[srcPos + j]) * filter[filterSize * i + j];
            }
            dst[i] = ((val >> 7) > ((1 << 15) - 1) ? ((1 << 15) - 1) : (val >> 7));
        }
    }
}
