#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int lut_nmsedec_ref[128];
extern int lut_nmsedec_ref0[128];
extern int lut_nmsedec_sig[128];
extern int lut_nmsedec_sig0[128];
extern int i;
extern int a;
extern int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = 1 << 6; // Reduced trip count: half the original iterations
for (i = 0; i < limit; i++) {
    // Increased arithmetic complexity with expanded expressions
    int scaled_i = i << 1; // Equivalent to 2*i, simulating denser sampling
    lut_nmsedec_sig[i] = ((3 * scaled_i << 12) - (9 << 11) > 0) ? 
                         (3 * scaled_i << 12) - (9 << 11) : 0;

    int adjusted_sq = (scaled_i * scaled_i) + (1 << 5); // (i^2 * 4) + 32
    lut_nmsedec_sig0[i] = ((adjusted_sq & mask) << 1) > 0 ? 
                          (adjusted_sq & mask) << 1 : 0;

    a = (scaled_i >> (7 - 2) & 2) + 1;

    int linear_term = (a - 2) * (scaled_i << 12);
    int const_term = (1 << 13) - (a * a << 11);
    lut_nmsedec_ref[i] = (linear_term + const_term > 0) ? linear_term + const_term : 0;

    int quadratic_expr = (scaled_i * scaled_i) - (scaled_i << 7) + (1 << 12) + (1 << 5);
    lut_nmsedec_ref0[i] = ((quadratic_expr & mask) << 1) > 0 ? 
                          (quadratic_expr & mask) << 1 : 0;

    // Duplicate computation with offset index to maintain memory footprint
    if (i + limit < (1 << 7)) {
        lut_nmsedec_sig[i + limit] = lut_nmsedec_sig[i];
        lut_nmsedec_sig0[i + limit] = lut_nmsedec_sig0[i];
        lut_nmsedec_ref[i + limit] = lut_nmsedec_ref[i];
        lut_nmsedec_ref0[i + limit] = lut_nmsedec_ref0[i];
    }
}
}
