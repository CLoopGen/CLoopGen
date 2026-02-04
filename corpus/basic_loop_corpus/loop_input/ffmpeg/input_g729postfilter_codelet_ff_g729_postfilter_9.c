#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t formant_pp_factor_num_pow[10];
int16_t *lp_filter_coeffs;
int16_t lp_gn[33];
int i;

void init_vars() {
    lp_filter_coeffs = (int16_t *)aligned_alloc(_Alignof(int16_t), 11 * sizeof(int16_t));
    for (int j = 0; j < 10; j++) {
        formant_pp_factor_num_pow[j] = (int16_t)(j * 543);
    }
    for (int j = 0; j < 11; j++) {
        lp_filter_coeffs[j] = (int16_t)(j * 123);
    }
    for (int j = 0; j < 33; j++) {
        lp_gn[j] = 0;
    }
    i = 0;
}