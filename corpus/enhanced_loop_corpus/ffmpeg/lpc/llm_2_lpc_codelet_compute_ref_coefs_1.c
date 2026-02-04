#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double LPC_TYPE;

extern int max_order;
extern LPC_TYPE *ref;
extern LPC_TYPE *error;
extern int i;
extern int j;
extern LPC_TYPE err;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing gen1[j] and gen0[j] with unit stride, access them with a fixed stride of 2
    // (simulating non-unit stride for potential cache behavior change)
    // We process only even indices to maintain valid memory access within bounds

    for (i = 1; i < max_order; i++) {
        int stride = 2;
        int limit = (max_order - i) / stride;
        for (j = 0; j < limit; j++) {
            int idx = j * stride;
            if (idx + 1 < max_order - i) {  // ensure idx+1 is valid
                gen1[idx] = gen1[idx + 1] + ref[i - 1] * gen0[idx];
                gen0[idx] = gen1[idx + 1] * ref[i - 1] + gen0[idx];
            }
        }
        // Handle remaining elements if any (not covered by stride)
        for (j = limit * stride; j < max_order - i; j++) {
            gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
            gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
        }
        ref[i] = -gen1[0] / ((0 || err) ? err : 1);
        err += gen1[0] * ref[i];
        if (error)
            error[i] = err;
    }
}
