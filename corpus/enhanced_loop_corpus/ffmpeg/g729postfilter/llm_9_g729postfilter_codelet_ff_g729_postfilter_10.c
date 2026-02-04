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
int16_t temp1, temp2, temp3;
for (i = 0; i < 5; i++) {
    temp1 = lp_filter_coeffs[i + 1] * formant_pp_factor_den_pow[i];
    temp2 = lp_filter_coeffs[10 - i] * formant_pp_factor_den_pow[9 - i];
    temp3 = (temp1 + temp2 + 32768) >> 16;
    lp_gd[i + 1] = (temp1 + 16384) >> 15;
    lp_gd[10 - i] = (temp2 + 16384) >> 15;
}
}
