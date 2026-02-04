#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int len;
extern int order;
extern  int32_t *coefs;
extern int shift;
extern int big;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reduced loop nesting by unrolling the switch-case logic into a precomputed loop.
    // This variant eliminates the switch and replaces it with a direct loop over coefficients,
    // reducing control complexity and increasing regularity. Only one loop remains.

    for (i = order; i < len; i += 2) {
        int32_t p0 = 0, p1 = 0;
        int max_order = big ? 32 : 8;

        // Unroll the coefficient accumulation using a counted loop instead of switch
        for (int k = max_order; k >= 1; k--) {
            int coef_idx = k - 1;
            int c = coefs[coef_idx];
            int s0 = smp[i - k];
            int s1 = smp[i - k + 1];
            p0 += c * s0;
            p1 += c * s1;
        }

        res[i] = smp[i] - (p0 >> shift);
        res[i + 1] = smp[i + 1] - (p1 >> shift);
    }
}
