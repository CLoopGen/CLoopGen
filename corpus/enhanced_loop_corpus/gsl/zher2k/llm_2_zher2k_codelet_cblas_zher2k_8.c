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
extern double alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reformulate array accesses to promote consecutive memory reads by precomputing base pointers per k iteration
    for (k = 0; k < K; k++) {
        const double *A_k = (const double *)A + 2 * k * lda;
        const double *B_k = (const double *)B + 2 * k * ldb;
        for (i = 0; i < N; i++) {
            double Aki_real = A_k[2 * i];
            double Aki_imag = A_k[2 * i + 1];
            double Bki_real = B_k[2 * i];
            double Bki_imag = B_k[2 * i + 1];
            double temp1_real = alpha_real * Aki_real - alpha_imag * (-Aki_imag);
            double temp1_imag = alpha_real * (-Aki_imag) + alpha_imag * Aki_real;
            double temp2_real = alpha_real * Bki_real - alpha_imag * Bki_imag;
            double temp2_imag = -(alpha_real * Bki_imag + alpha_imag * Bki_real);
            for (j = 0; j < i; j++) {
                double Akj_real = A_k[2 * j];
                double Akj_imag = A_k[2 * j + 1];
                double Bkj_real = B_k[2 * j];
                double Bkj_imag = B_k[2 * j + 1];
                double *Cij = (double *)C + 2 * (i * lda + j);
                Cij[0] += (temp1_real * Bkj_real - temp1_imag * Bkj_imag) + (temp2_real * Akj_real - temp2_imag * Akj_imag);
                Cij[1] += (temp1_real * Bkj_imag + temp1_imag * Bkj_real) + (temp2_real * Akj_imag + temp2_imag * Akj_real);
            }
            double *Cii = (double *)C + 2 * (i * lda + i);
            Cii[0] += 2 * (temp1_real * Bki_real - temp1_imag * Bki_imag);
            Cii[1] = 0.;
        }
    }
}
