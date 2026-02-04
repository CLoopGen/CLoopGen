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
    for (j = i; j < N && j < i + 4; j++) {
        double temp_real = 0.;
        double temp_imag = 0.;
        for (k = 0; k < K; k++) {
            const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag = -(((const double *)A)[2 * (k * lda + i) + 1]);
            const double Akj_real = (((const double *)A)[2 * (k * lda + j)]);
            const double Akj_imag = (((const double *)A)[2 * (k * lda + j) + 1]);
            temp_real += Aki_real * Akj_real - Aki_imag * Akj_imag;
            temp_imag += Aki_real * Akj_imag + Aki_imag * Akj_real;
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
    }
    for (j = i + 4; j < N; j += 4) {
        double temp_real[4] = {0.};
        double temp_imag[4] = {0.};
        int j_vec[4] = {j, j+1, j+2, j+3};
        for (k = 0; k < K; k++) {
            const double Aki_real = (((const double *)A)[2 * (k * lda + i)]);
            const double Aki_imag = -(((const double *)A)[2 * (k * lda + i) + 1]);
            for (int v = 0; v < 4; v++) {
                if (j_vec[v] >= N) continue;
                const double Akj_real = (((const double *)A)[2 * (k * lda + j_vec[v])]);
                const double Akj_imag = (((const double *)A)[2 * (k * lda + j_vec[v]) + 1]);
                temp_real[v] += Aki_real * Akj_real - Aki_imag * Akj_imag;
                temp_imag[v] += Aki_real * Akj_imag + Aki_imag * Akj_real;
            }
        }
        for (int v = 0; v < 4; v++) {
            if (j_vec[v] >= N) break;
            (((double *)C)[2 * (i * ldc + j_vec[v])]) += alpha * temp_real[v];
            (((double *)C)[2 * (i * ldc + j_vec[v]) + 1]) += alpha * temp_imag[v];
        }
    }
}
}
