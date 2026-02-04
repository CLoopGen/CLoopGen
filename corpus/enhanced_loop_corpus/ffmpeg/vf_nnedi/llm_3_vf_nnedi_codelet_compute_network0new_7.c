#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *wf;
extern float vals[8];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Change inner loop to stride through 'wf' with a fixed step, increasing spatial separation
    // Use a strided access pattern: start from different base and use larger stride
    for (i = 0; i < 4; i++) {
        float sum = 0.F;
        for (j = 0; j < 4; j++) {
            // Instead of j << 2, use a fixed stride of 8 for non-contiguous access
            int idx = 8 + (j << 3) + i; // Stride of 8 instead of 4: more scattered access
            sum += vals[j] * wf[idx];
        }
        // Adjust final access to maintain correctness: original offset was 24+i
        vals[4 + i] = sum + wf[24 + i];
    }
}
