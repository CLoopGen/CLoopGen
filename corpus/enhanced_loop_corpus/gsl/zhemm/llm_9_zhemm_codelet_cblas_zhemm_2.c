#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce computational intensity by blocking and simplifying updates
// Use a lower trip count via step-increments and reduce arithmetic density
for (i = 0; i < n1; i += 2) {
    for (j = 0; j < n2; j += 2) {
        for (int ii = 0; ii < 2 && (i + ii) < n1; ++ii) {
            for (int jj = 0; jj < 2 && (j + jj) < n2; ++jj) {
                int ci = i + ii;
                int cj = j + jj;
                const double Bij_real = (((const double *)B)[2 * (ldb * ci + cj)]);
                const double Bij_imag = (((const double *)B)[2 * (ldb * ci + cj) + 1]);
                const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
                const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
                double temp2_real = 0.;
                double temp2_imag = 0.;

                const double Aii_real = (((const double *)A)[2 * (ci * lda + ci)]);
                (((double *)C)[2 * (ci * ldc + cj)]) += temp1_real * Aii_real;
                (((double *)C)[2 * (ci * ldc + cj) + 1]) += temp1_imag * Aii_real;

                for (k = ci + 1; k < n1; k++) {
                    const double Aik_real = (((const double *)A)[2 * (ci * lda + k)]);
                    const double Aik_imag = (((const double *)A)[2 * (ci * lda + k) + 1]);
                    const double Bkj_real = (((const double *)B)[2 * (ldb * k + cj)]);
                    const double Bkj_imag = (((const double *)B)[2 * (ldb * k + cj) + 1]);

                    // Simplified accumulation: merge conjugate logic directly
                    double c_prod_real = Aik_real * temp1_real + Aik_imag * temp1_imag;
                    double c_prod_imag = Aik_real * temp1_imag - Aik_imag * temp1_real;
                    (((double *)C)[2 * (k * ldc + cj)]) += c_prod_real;
                    (((double *)C)[2 * (k * ldc + cj) + 1]) += c_prod_imag;

                    temp2_real += Aik_real * Bkj_real - Aik_imag * Bkj_imag;
                    temp2_imag += Aik_real * Bkj_imag + Aik_imag * Bkj_real;
                }
                (((double *)C)[2 * (ci * ldc + cj)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
                (((double *)C)[2 * (ci * ldc + cj) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
            }
        }
    }
}
}
