#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t formant_pp_factor_den_pow[10];
extern  int16_t *lp_filter_coeffs;
extern int16_t lp_gd[11];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 10; i += 2) {
    lp_gd[i + 1] = (lp_filter_coeffs[i + 1] * formant_pp_factor_den_pow[i] + 16384) >> 15;
    if (i + 1 < 10) {
        lp_gd[i + 2] = (lp_filter_coeffs[i + 2] * formant_pp_factor_den_pow[i + 1] + 16384) >> 15;
    }
}
}
