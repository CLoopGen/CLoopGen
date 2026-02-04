#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t gt16x16_cnst[64] __attribute__((aligned(64)));
extern int16_t *coeffs;
extern int16_t i;
extern int16_t j;
extern int16_t k;
extern int16_t *buf_ptr;
extern int16_t *src;
extern  int16_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i > 0; i--) {
        int16_t sum0, sum1, sum2, sum3;
        k = 0;
        for (j = 0; j < 2; j++) {
            sum0 = sum1 = sum2 = sum3 = 0;
            for (int m = 0; m < 16; m++) {
                int16_t f_val = filter[m];
                sum0 += src[m + 0*16] * f_val;
                sum1 += src[m + 1*16] * f_val;
                sum2 += src[m + 2*16] * f_val;
                sum3 += src[m + 3*16] * f_val;
            }
            coeffs[k++] = sum0;
            coeffs[k++] = sum1;
            coeffs[k++] = sum2;
            coeffs[k++] = sum3;
            src += 64;
            filter += 16;
        }
        buf_ptr = coeffs + 4;
    }
}
