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
    // Variant 2: Strided memory access — traverse columns first with explicit striding over i, processing every ldb-th element
    double *B_ptr = (double *)B;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            const int offset = 2 * (ldb * i + j);
            const double temp_real = B_ptr[offset];
            const double temp_imag = B_ptr[offset + 1];
            B_ptr[offset]     = alpha_real * temp_real - alpha_imag * temp_imag;
            B_ptr[offset + 1] = alpha_real * temp_imag + alpha_imag * temp_real;
        }
    }
}
