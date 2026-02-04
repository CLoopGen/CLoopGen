#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern  double beta_real;
extern  double beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) { // Increase outer loop stride, reducing iterations but increasing per-iteration work
    const int i_end = (i + 1 < N) ? i + 2 : i + 1;
    for (j = 0; j <= i; j++) {
        // Process current row i
        const double Cij_real = (((double *)C)[2 * (ldc * i + j)]);
        const double Cij_imag = (((double *)C)[2 * (ldc * i + j) + 1]);
        (((double *)C)[2 * (ldc * i + j)]) = beta_real * Cij_real - beta_imag * Cij_imag;
        (((double *)C)[2 * (ldc * i + j) + 1]) = beta_real * Cij_imag + beta_imag * Cij_real;

        // Process next row i+1 if within bounds
        if (i + 1 < N && j <= i + 1) {
            const double Ci1j_real = (((double *)C)[2 * (ldc * (i+1) + j)]);
            const double Ci1j_imag = (((double *)C)[2 * (ldc * (i+1) + j) + 1]);
            (((double *)C)[2 * (ldc * (i+1) + j)]) = beta_real * Ci1j_real - beta_imag * Ci1j_imag;
            (((double *)C)[2 * (ldc * (i+1) + j) + 1]) = beta_real * Ci1j_imag + beta_imag * Ci1j_real;
        }
    }
}
}
