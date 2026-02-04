#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *B_ptr = (double *)B;
    for (i = 0; i < n1; i++) {
        int base_idx = ldb * i;
        double real_accum = 0.0;
        double imag_accum = 0.0;
        for (j = 0; j < n2; j++) {
            int idx = 2 * (base_idx + j);
            double Bij_real = B_ptr[idx];
            double Bij_imag = B_ptr[idx + 1];
            real_accum += Bij_real;
            imag_accum += Bij_imag;
            B_ptr[idx] = alpha_real * Bij_real - alpha_imag * Bij_imag;
        }
        // Introduce a loop-carried dependency via accumulation (WAW and RAW on accumulators)
        for (j = 0; j < n2; j++) {
            int idx = 2 * (base_idx + j) + 1;
            B_ptr[idx] = alpha_real * B_ptr[idx] + alpha_imag * B_ptr[idx - 1] + real_accum * 0.001;
        }
    }
}
