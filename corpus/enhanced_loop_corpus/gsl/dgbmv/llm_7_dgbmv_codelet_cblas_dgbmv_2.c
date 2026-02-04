#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern int L;
extern int U;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_accum = 0.0;
int last_i = -1;
for (i = 0; i < lenY; i++) {
    double temp = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    int jx = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    for (j = j_min; j < j_max; j++) {
        temp += X[jx] * A[(L - i + j) + i * lda];
        jx += incX;
    }
    temp_accum += temp; // Introduce accumulation across iterations (WAW dependency on temp_accum)
    if (i == lenY - 1) {
        Y[iy - (lenY - 1) * incY] += alpha * temp_accum; // Apply accumulated sum to first output element
    }
    Y[iy] = 0.0; // WAW: overwrite Y[iy] regardless of computation, breaking original flow dependence
    iy += incY;
    last_i = i;
}
// Eliminate per-element update; instead, only one write uses the total sum
// This creates a loop-carried WAW on temp_accum and breaks the original RAW/WAR pattern
}
