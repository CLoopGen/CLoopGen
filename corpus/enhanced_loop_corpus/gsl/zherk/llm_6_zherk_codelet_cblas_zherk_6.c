#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        // Introduce a local accumulation array to break potential WAW hazards and reorganize computation
        double accum[2] = {0.0, 0.0};
        for (k = 0; k < K; k++) {
            const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag = -(((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            // Modify data dependency: fuse operations into a single temporary pair to alter RAW/WAR pattern
            accum[0] += Aki_real * Akj_real - Aki_imag * Akj_imag;
            accum[1] += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        temp_real = accum[0];
        temp_imag = accum[1];
        (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
    }
}
}
