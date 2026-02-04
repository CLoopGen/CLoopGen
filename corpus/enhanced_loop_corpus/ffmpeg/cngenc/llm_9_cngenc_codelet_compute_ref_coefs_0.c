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
    // Variant 2: Reduced trip count with conditional internal branching to simulate variable work per iteration
    int i;
    int step = (max_order > 16) ? 2 : 1;  // Adjust stride based on order, reducing effective iterations
    for (i = 0; i < max_order; i += step) {
        // Perform main assignment
        gen0[i] = gen1[i] = autoc[i + 1];

        // Occasionally perform additional work every 4th effective iteration
        if ((i / step) % 4 == 3) {
            // Introduce auxiliary computation on a fixed subset of elements to vary intensity
            int j;
            for (j = 1; j < 5 && (i - j) >= 0; j++) {
                gen0[i - j] = (gen0[i - j] + gen1[i - j]) * 0.5f;  // Smoothing-like operation
            }
        }
    }
    // Final pass to ensure all elements are at least assigned once if step > 1
    if (step > 1) {
        for (i = 1; i < max_order; i += 1) {
            if (i % step != 0) {
                gen0[i] = gen1[i] = autoc[i + 1];
            }
        }
    }
}
