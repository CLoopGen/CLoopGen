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
// Reduce computational intensity by blocking and decreasing trip count via step size
const int block_size = 2;
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j += block_size) {
        // Process two j-values at a time if within bounds
        for (int jb = 0; jb < block_size && (j + jb) < n2; jb++) {
            const int j_idx = j + jb;
            const double Bij_real = (((const double *)B)[2 * (ldb * i + j_idx)]);
            const double Bij_imag = (((const double *)B)[2 * (ldb * i + j_idx) + 1]);
            const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
            const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
            double temp2_real = 0.;
            double temp2_imag = 0.;

            const double Ajj_real = (((const double *)A)[2 * (j_idx * lda + j_idx)]);
            const double Ajj_imag = (((const double *)A)[2 * (j_idx * lda + j_idx) + 1]);
            (((double *)C)[2 * (i * ldc + j_idx)]) += temp1_real * Ajj_real - temp1_imag * Ajj_imag;
            (((double *)C)[2 * (i * ldc + j_idx) + 1]) += temp1_real * Ajj_imag + temp1_imag * Ajj_real;

            for (k = j_idx + 1; k < n2; k++) {
                const double Ajk_real = (((const double *)A)[2 * (j_idx * lda + k)]);
                const double Ajk_imag = (((const double *)A)[2 * (j_idx * lda + k) + 1]);
                const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
                const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);
                (((double *)C)[2 * (i * ldc + k)]) += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
                (((double *)C)[2 * (i * ldc + k) + 1]) += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
                temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
                temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
            }
            (((double *)C)[2 * (i * ldc + j_idx)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
            (((double *)C)[2 * (i * ldc + j_idx) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
        }
    }
}
}
