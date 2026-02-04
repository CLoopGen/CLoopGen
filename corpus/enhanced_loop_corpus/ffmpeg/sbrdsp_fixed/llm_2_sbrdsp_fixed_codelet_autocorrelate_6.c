#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int x[40][2];
extern int lag;
extern int i;
extern int64_t accu_re;
extern int64_t accu_im;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reordering computations to access x[i] and x[i+lag] in strides
    // This variant assumes lag is small and positive, and we precompute base pointers to improve spatial locality.
    int64_t temp_re = 0;
    int64_t temp_im = 0;
    const int *x_ptr_0 = &x[1][0];
    const int *x_ptr_lag = &x[1 + lag][0];

    for (i = 1; i < 38; i++) {
        temp_re += (uint64_t)x_ptr_0[0] * x_ptr_lag[0];
        temp_re += (uint64_t)x_ptr_0[1] * x_ptr_lag[1];
        temp_im += (uint64_t)x_ptr_0[0] * x_ptr_lag[1];
        temp_im -= (uint64_t)x_ptr_0[1] * x_ptr_lag[0];

        x_ptr_0 += 2;  // Move to next row in x[i]
        x_ptr_lag += 2; // Move to next row in x[i+lag]
    }
    accu_re += temp_re;
    accu_im += temp_im;
}
