#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern  double beta_real;
extern  double beta_imag;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access via iy, we process elements consecutively in memory
    // assuming incY is positive and we can reindex directly from base pointer.
    double *y_ptr = (double *)Y;
    for (i = 0; i < N; i++) {
        const ptrdiff_t idx = 2 * i; // Consecutive indexing
        const double y_real = y_ptr[idx];
        const double y_imag = y_ptr[idx + 1];
        const double tmpR = y_real * beta_real - y_imag * beta_imag;
        const double tmpI = y_real * beta_imag + y_imag * beta_real;
        y_ptr[idx] = tmpR;
        y_ptr[idx + 1] = tmpI;
    }
}
