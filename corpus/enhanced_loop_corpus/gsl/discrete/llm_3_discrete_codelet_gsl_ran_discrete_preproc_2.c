#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t Kevents;
extern size_t k;
extern size_t nBigs;
extern size_t nSmalls;
extern double *E;
extern double mean;
extern size_t * which;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (simulating non-linear access)
    // Assume 'which' could also serve as a temporary index buffer if pre-initialized, but here we use a local temp idea.
    // Since we cannot modify function signature, we simulate indirect access via arithmetic permutation.
    // Using bit-reversal inspired indexing for indirect pattern (simplified version for power-of-2 near Kevents)

    nSmalls = 0;
    nBigs = 0;
    size_t stride = 1;
    while (stride * 2 < Kevents) stride *= 2;

    for (size_t base = 0; base < stride; ++base) {
        for (k = 0; k < Kevents; k++) {
            size_t idx = base + (k * stride);
            if (idx >= Kevents) break;
            if (E[idx] < mean) {
                ++nSmalls;
                which[idx] = 0;
            } else {
                ++nBigs;
                which[idx] = 1;
            }
        }
    }
}
