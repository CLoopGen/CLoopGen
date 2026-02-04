#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern int max_order;
extern LPC_TYPE *ref;
extern LPC_TYPE *error;
extern int i;
extern int j;
extern LPC_TYPE err;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2 (simulating non-unit stride usage)
    // We simulate a strided access pattern by stepping through indices with a fixed increment,
    // but still cover all necessary elements by adjusting loop bounds accordingly.
    // This can model situations where data is interleaved or padding exists.
    const int stride = 2;
    for (i = 1; i < max_order; i++) {
        int valid_ops = max_order - i;
        // Process in two passes to maintain correctness under stride simulation
        // Pass 1: even-like indices (0, 2, 4, ...)
        for (j = 0; j < valid_ops; j += stride) {
            if (j + 1 < max_order - i) {  // Ensure j+1 is valid
                gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
                gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
            }
        }
        // Pass 2: odd-like indices (1, 3, 5, ...)
        for (j = 1; j < valid_ops; j += stride) {
            if (j + 1 < max_order - i) {
                gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
                gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
            }
        }
        // Handle edge case for last element if not covered due to stride
        if (valid_ops > 0 && (valid_ops - 1) % stride != 0) {
            j = valid_ops - 1;
            gen1[j] = gen1[j + 1] + ref[i - 1] * gen0[j];
            gen0[j] = gen1[j + 1] * ref[i - 1] + gen0[j];
        }
        ref[i] = -gen1[0] / ((0 || err) ? err : 1);
        err += gen1[0] * ref[i];
        if (error)
            error[i] = err;
    }
}
