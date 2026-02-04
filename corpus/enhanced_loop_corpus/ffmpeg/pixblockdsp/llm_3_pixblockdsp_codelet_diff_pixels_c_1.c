#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *restrict block;
extern  uint8_t *s1;
extern  uint8_t *s2;
extern ptrdiff_t stride;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal order (backward indexing)
    // We change the access pattern to step through arrays using a negative effective stride
    // and process elements from the end to simulate different cache behavior.
    ptrdiff_t idx = 7 * stride; // Start at last row index
    for (i = 0; i < 8; i++) {
        block[0] = s1[idx + 0] - s2[idx + 0];
        block[1] = s1[idx + 1] - s2[idx + 1];
        block[2] = s1[idx + 2] - s2[idx + 2];
        block[3] = s1[idx + 3] - s2[idx + 3];
        block[4] = s1[idx + 4] - s2[idx + 4];
        block[5] = s1[idx + 5] - s2[idx + 5];
        block[6] = s1[idx + 6] - s2[idx + 6];
        block[7] = s1[idx + 7] - s2[idx + 7];
        idx -= stride;  // Move to previous row (reverse direction)
        block += 8;
    }
}
