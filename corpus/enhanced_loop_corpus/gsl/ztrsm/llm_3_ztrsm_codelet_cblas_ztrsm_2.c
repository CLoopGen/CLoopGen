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
    // Variant 2: Strided memory access with stride of 2 in j-loop to process complex numbers in a non-unit stride pattern
    for (i = 0; i < n1; i++) {
        for (j = 0; j < 2 * n2; j += 2) {
            const ptrdiff_t base_idx = ldb * i + j / 2;
            const ptrdiff_t idx = 2 * base_idx;
            const double Bij_real = ((double *)B)[idx];
            const double Bij_imag = ((double *)B)[idx + 1];
            ((double *)B)[idx]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
            ((double *)B)[idx + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
