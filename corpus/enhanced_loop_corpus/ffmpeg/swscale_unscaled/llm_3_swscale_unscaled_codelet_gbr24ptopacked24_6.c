#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src[];
extern int srcStride[];
extern uint8_t *dst;
extern int dstStride;
extern int srcSliceH;
extern int width;
extern int x;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using indirect indexing via index array (simulated stride pattern)
    ptrdiff_t idx[3] = {0}; // Simulate base offsets for each source

    for (h = 0; h < srcSliceH; h++) {
        uint8_t *dest = dst + dstStride * h;

        for (x = 0; x < width; x++) {
            *dest++ = src[0][idx[0]];
            *dest++ = src[1][idx[1]];
            *dest++ = src[2][idx[2]];
            // Update indices with fixed step (could be varied in more complex patterns)
            idx[0]++;
            idx[1]++;
            idx[2]++;
        }

        // Advance each source pointer by its stride after processing the row
        src[0] += srcStride[0];
        src[1] += srcStride[1];
        src[2] += srcStride[2];
    }
}
