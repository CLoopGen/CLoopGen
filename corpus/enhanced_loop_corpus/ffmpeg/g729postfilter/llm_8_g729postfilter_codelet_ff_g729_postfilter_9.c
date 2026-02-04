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
for (i = 0; i < 20; i += 2)
    lp_gn[i/2 + 11] = (lp_filter_coeffs[i/2 + 1] * formant_pp_factor_num_pow[i/2] + 16384) >> 15;
}
