#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t formant_pp_factor_num_pow[10];
extern  int16_t *lp_filter_coeffs;
extern int16_t lp_gn[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    for (i = 9; i >= 0; i--)
        lp_gn[i + 11] = (lp_filter_coeffs[i + 1] * formant_pp_factor_num_pow[i] + 16384) >> 15;
}
