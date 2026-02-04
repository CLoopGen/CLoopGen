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
        double local_alpha_real = alpha_real;
        double local_alpha_imag = alpha_imag;
        for (j = 0; j < n2; j++) {
            int idx = 2 * (base_idx + j);
            double Bij_real = B_ptr[idx];
            double Bij_imag = B_ptr[idx + 1];
            double result_real = local_alpha_real * Bij_real - local_alpha_imag * Bij_imag;
            double result_imag = local_alpha_real * Bij_imag + local_alpha_imag * Bij_real;
            B_ptr[idx] = result_real;
            B_ptr[idx + 1] = result_imag;
        }
    }
}
