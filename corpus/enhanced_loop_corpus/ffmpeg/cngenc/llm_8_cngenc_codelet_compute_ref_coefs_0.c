#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern  LPC_TYPE *autoc;
extern int max_order;
extern int i;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with repeated assignments and increased effective trip count via unrolling
    int i;
    for (i = 0; i < max_order; i += 2) {
        // Unroll by 2 and add redundant but safe computations to increase arithmetic operations
        gen0[i] = gen1[i] = autoc[i + 1];
        if (i + 1 < max_order) {
            gen0[i + 1] = gen1[i + 1] = autoc[i + 2];  // Extra computation per iteration
        }
        // Add dummy arithmetic to increase computational load without affecting correctness
        gen0[i] += (LPC_TYPE)0.0001f;
        gen0[i] -= (LPC_TYPE)0.0001f;
        if (i + 1 < max_order) {
            gen0[i + 1] += (LPC_TYPE)0.0001f;
            gen0[i + 1] -= (LPC_TYPE)0.0001f;
        }
    }
}
