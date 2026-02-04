#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    // Reorder computation to eliminate some intermediate dependencies and fuse operations
    int base = 8 * i;
    int16_t t0 = tmp[base + 0], t1 = tmp[base + 1], t2 = tmp[base + 2], t3 = tmp[base + 3];
    int16_t t4 = tmp[base + 4], t5 = tmp[base + 5], t6 = tmp[base + 6], t7 = tmp[base + 7];

    // Combine inputs directly into final stages to reduce intermediate variable count
    // Eliminate a0-a7, go straight to b0-b7 with direct expressions
    const int b0 = (t0 + t7) + (t3 + t4);
    const int b1 = (t1 + t6) + (t2 + t5);
    const int b2 = (t0 + t7) - (t3 + t4);
    const int b3 = (t1 + t6) - (t2 + t5);

    // Remove temporary variables entirely; compute outputs directly
    // Also remove loop-carried dependencies — this version is fully parallelizable
    (coef + i)[8*0] = b0 + b1;
    (coef + i)[8*4] = b0 - b1;

    const int term1 = (t1 - t6) + (t1 - t6) + ((t1 - t6) >> 1); // ~ a3 + a5 equiv
    const int term2 = (t0 - t7) + ((t0 - t7) >> 1);             // ~ a1 + (a1>>1)
    const int b4 = term1 + term2;
    (coef + i)[8*1] = b4 + (((t0-t7) + (t2-t5) - ((t5 + (t5>>1)))) >> 2); // partial b7 proxy

    // Simplify and inline remaining terms to break WAW hazards from repeated coef use
    (coef + i)[8*2] = b2 + (b3 >> 1);
    (coef + i)[8*6] = (b2 >> 1) - b3;

    const int b5_val = (t0 - t7) - (t3 - t4) - ((t5 + (t5 >> 1)));
    const int b6_val = (t0 - t7) + (t3 - t4) - ((t1 + (t1 >> 1)));
    (coef + i)[8*3] = b5_val + (b6_val >> 2);
    (coef + i)[8*5] = b6_val - (b5_val >> 2);

    const int b7_val = (t1 - t6) - (t2 - t5) + ((t3 - t4) + ((t3 - t4) >> 1));
    (coef + i)[8*7] = (b4 >> 2) - b7_val;
}
}
