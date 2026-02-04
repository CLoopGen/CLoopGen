#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nb_exponent;
extern int msk_val[50];
extern  uint16_t *hearing_thresh;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolling by factor of 2
    // Process even indices first, then handle odd if nb_exponent is odd
    int stride = 2;
    int limit = nb_exponent - (nb_exponent % stride);
    for (i = 0; i < limit; i += stride) {
        msk_val[i] = (msk_val[i] > hearing_thresh[i]) ? msk_val[i] : hearing_thresh[i];
        msk_val[i + 1] = (msk_val[i + 1] > hearing_thresh[i + 1]) ? msk_val[i + 1] : hearing_thresh[i + 1];
    }
    // Handle remaining element if nb_exponent is odd
    if (limit < nb_exponent) {
        i = nb_exponent - 1;
        msk_val[i] = (msk_val[i] > hearing_thresh[i]) ? msk_val[i] : hearing_thresh[i];
    }
}
