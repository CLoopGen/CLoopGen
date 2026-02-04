#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  void *A;
extern  int lda;
extern  void *B;
extern  int ldb;
extern void *C;
extern int i;
extern int j;
extern int k;
extern  double alpha_real;
extern  double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k++) {
    const double *A_ptr = (const double *)A + 2 * k * lda;
    const double *B_ptr = (const double *)B + 2 * k * ldb;
    for (i = 0; i < N; i++) {
        double Aki_real = A_ptr[2 * i];
        double Aki_imag = A_ptr[2 * i + 1];
        double Bki_real = B_ptr[2 * i];
        double Bki_imag = B_ptr[2 * i + 1];
        double temp1_real = alpha_real * Aki_real - alpha_imag * Aki_imag;
        double temp1_imag = alpha_real * Aki_imag + alpha_imag * Aki_real;
        double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
        double temp2_imag = alpha_real * Bki_imag + alpha_imag * Bki_real;
        const double *Akj_base = A_ptr;
        const double *Bkj_base = B_ptr;
        for (j = 0; j <= i; j++) {
            double Akj_real = Akj_base[2 * j];
            double Akj_imag = Akj_base[2 * j + 1];
            double Bkj_real = Bkj_base[2 * j];
            double Bkj_imag = Bkj_base[2 * j + 1];
            double *Cij = (double *)C + 2 * (i * lda + j);
            Cij[0] += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
            Cij[1] += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
        }
    }
}
}
