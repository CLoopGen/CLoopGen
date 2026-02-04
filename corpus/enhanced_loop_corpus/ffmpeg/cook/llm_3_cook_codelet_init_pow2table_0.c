#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float pow2tab[127];
extern float rootpow2tab[127];
extern int i;
extern  float exp2_tab[2];
extern float exp2_val;
extern float root_val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access with Increased Stride (simulated unrolling effect)
    // Access pattern modified to write every 2nd element first, then fill gaps.
    // This creates a strided access pattern which may be useful for SIMD or prefetching optimization.
    exp2_val = 1.0f;
    root_val = 0.5f;

    // First pass: write elements with stride 2 (even indices in logical sequence)
    for (i = -63; i < 64; i += 2) {
        int idx = 63 + i;
        if (!(i & 1))
            root_val *= 2;
        pow2tab[idx] = exp2_val;
        rootpow2tab[idx] = root_val * exp2_tab[i & 1];
        exp2_val *= 4;  // Since we skip one iteration, multiply by 2^2
    }

    // Reset exp2_val to correct intermediate state before second pass
    exp2_val = 2.0f;
    root_val = 0.5f;

    // Second pass: fill in the odd steps (odd indices in logical sequence)
    for (i = -62; i < 64; i += 2) {
        int idx = 63 + i;
        if (!(i & 1))
            root_val *= 2;
        pow2tab[idx] = exp2_val;
        rootpow2tab[idx] = root_val * exp2_tab[i & 1];
        exp2_val *= 4;
    }
}
