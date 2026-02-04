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
for (i = 0; i < (1 << 7); i++) {
    if (i % 4 == 0) {
        lut_nmsedec_sig[i] = 0;
        lut_nmsedec_sig0[i] = 0;
        lut_nmsedec_ref[i] = 0;
        lut_nmsedec_ref0[i] = 0;
        continue;
    }

    int base_shift = 13 - (7 - 1);
    int sig_val = (3 * i << base_shift) - (9 << 11);
    lut_nmsedec_sig[i] = sig_val > 0 ? sig_val : 0;

    int adjusted_square = i * i + ((1 << (7 - 1)) - 1);
    lut_nmsedec_sig0[i] = ((adjusted_square & mask) << 1) > 0 ? (adjusted_square & mask) << 1 : 0;

    a = ((i >> (7 - 2)) & 2) + 1;
    int linear_term = (a - 2) * (i << base_shift);
    int const_term = (1 << 13) - (a * a << 11);
    lut_nmsedec_ref[i] = (linear_term + const_term) > 0 ? linear_term + const_term : 0;

    int quadratic_expr = i * i - (i << 7) + (1 << (2 * (7 - 1))) + (1 << ((7 - 1) - 1));
    lut_nmsedec_ref0[i] = ((quadratic_expr & mask) << 1) > 0 ? (quadratic_expr & mask) << 1 : 0;
}
}
