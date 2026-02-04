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
int j;
for (i = 0; i < 5; i++) {
    j = i + 1;
    lp_gn[i + 11] = (lp_filter_coeffs[j] * formant_pp_factor_num_pow[i] + 16384) >> 15;
    lp_gn[i + 16] = (lp_filter_coeffs[j + 5] * formant_pp_factor_num_pow[i + 5] + 16384) >> 15;
}
}
