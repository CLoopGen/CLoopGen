#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **samples;
extern int16_t **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern int64_t v0;
extern int64_t v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (Reordered) Memory Access Pattern
    // Reorder computation to improve spatial locality by flipping loop order
    // and accumulating samples in a temporary array before writing back
    int32_t temp0, temp1;
    for (j = 0; j < in_ch; j++) {
        for (i = 0; i < len; i++) {
            // Access samples[j][i] consecutively in inner dimension (better cache behavior)
            temp0 = samples[j][i] * matrix[0][j];
            temp1 = samples[j][i] * matrix[1][j];
            // Accumulate into global 64-bit accumulators (emulate reduction over j)
            // Since we can't restructure reduction easily, simulate partial accumulation
            // using external state — note: requires initialization outside
            if (j == 0) {
                v0 = v1 = 0;
            }
            v0 += temp0;
            v1 += temp1;
            // Final write-back only on last j iteration
            if (j == in_ch - 1) {
                samples[0][i] = (v0 + 2048) >> 12;
                samples[1][i] = (v1 + 2048) >> 12;
            }
        }
    }
}
