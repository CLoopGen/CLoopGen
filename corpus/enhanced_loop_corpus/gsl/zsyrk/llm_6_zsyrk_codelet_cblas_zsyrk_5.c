#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        // Introduce a local accumulation array to break false WAW and WAR dependencies
        // by deferring write-back until after the k-loop completes.
        for (k = 0; k < K; k++) {
            const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag = (((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            // Modify dependency: accumulate into temporaries only, no indirect memory updates
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        // Single write to C after full reduction – eliminates partial WAW hazards on C
        double c_val_real = (((double *)C)[2 * (i * ldc + j)]);
        double c_val_imag = (((double *)C)[2 * (i * ldc + j) + 1]);
        c_val_real += alpha_real * temp_real - alpha_imag * temp_imag;
        c_val_imag += alpha_real * temp_imag + alpha_imag * temp_real;
        (((double *)C)[2 * (i * ldc + j)]) = c_val_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) = c_val_imag;
    }
}
}
