#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  double beta_real;
extern  double beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    const int stride_i = ldc * i;
    for (j = 0; j < n2; j++) {
        const int offset = 2 * (stride_i + j);
        const double Cij_real = ((double *)C)[offset];
        const double Cij_imag = ((double *)C)[offset + 1];
        
        if (beta_real != 1.0 || beta_imag != 0.0) {
            ((double *)C)[offset]     = beta_real * Cij_real - beta_imag * Cij_imag;
            ((double *)C)[offset + 1] = beta_real * Cij_imag + beta_imag * Cij_real;
        }
    }
}
}
