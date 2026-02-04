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
    if (lp_filter_coeffs == NULL || lp_gn == NULL || formant_pp_factor_num_pow == NULL) {
        return;
    }
    for (i = 0; i < 10; i++) {
        int32_t product = lp_filter_coeffs[i + 1] * formant_pp_factor_num_pow[i];
        if (product >= 0) {
            lp_gn[i + 11] = (product + 16384) >> 15;
        } else {
            lp_gn[i + 11] = (product - 16383) >> 15;
        }
    }
}
