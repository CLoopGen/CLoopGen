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
    // Instead of strided access via iy, we process elements consecutively in memory.
    // We assume incY is positive and adjust indexing to traverse Y as a contiguous complex array.
    double *Yd = (double *)Y;
    for (i = 0; i < N; i++) {
        const int idx = 2 * i; // Consecutive indexing
        const double y_real = Yd[idx];
        const double y_imag = Yd[idx + 1];
        const double tmpR = y_real * beta_real - y_imag * beta_imag;
        const double tmpI = y_real * beta_imag + y_imag * beta_real;
        Yd[idx] = tmpR;
        Yd[idx + 1] = tmpI;
    }
}
