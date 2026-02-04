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
        if (K > 0) {
            for (k = 0; k < K; k += 2) {
                const int index_ik = 2 * (i * lda + k);
                const int index_jk = 2 * (j * lda + k);
                const int index_bik = 2 * (i * ldb + k);
                const int index_bjk = 2 * (j * ldb + k);

                const double Aik_real = (((const double *)A)[index_ik]);
                const double Aik_imag = (((const double *)A)[index_ik + 1]);
                const double Bik_real = (((const double *)B)[index_bik]);
                const double Bik_imag = (((const double *)B)[index_bik + 1]);

                const double Ajk_real = (((const double *)A)[index_jk]);
                const double Ajk_imag = (((const double *)A)[index_jk + 1]);
                const double Bjk_real = (((const double *)B)[index_bjk]);
                const double Bjk_imag = (((const double *)B)[index_bjk + 1]);

                temp_real += (Aik_real * Bjk_real - Aik_imag * Bjk_imag) + (Bik_real * Ajk_real - Bik_imag * Ajk_imag);
                temp_imag += (Aik_real * Bjk_imag + Aik_imag * Bjk_real) + (Bik_real * Ajk_imag + Bik_imag * Ajk_real);

                if (k + 1 < K) {
                    const int index_ik1 = 2 * (i * lda + k + 1);
                    const int index_jk1 = 2 * (j * lda + k + 1);
                    const int index_bik1 = 2 * (i * ldb + k + 1);
                    const int index_bjk1 = 2 * (j * ldb + k + 1);

                    const double Aik1_real = (((const double *)A)[index_ik1]);
                    const double Aik1_imag = (((const double *)A)[index_ik1 + 1]);
                    const double Bik1_real = (((const double *)B)[index_bik1]);
                    const double Bik1_imag = (((const double *)B)[index_bik1 + 1]);

                    const double Ajk1_real = (((const double *)A)[index_jk1]);
                    const double Ajk1_imag = (((const double *)A)[index_jk1 + 1]);
                    const double Bjk1_real = (((const double *)B)[index_bjk1]);
                    const double Bjk1_imag = (((const double *)B)[index_bjk1 + 1]);

                    temp_real += (Aik1_real * Bjk1_real - Aik1_imag * Bjk1_imag) + (Bik1_real * Ajk1_real - Bik1_imag * Ajk1_imag);
                    temp_imag += (Aik1_real * Bjk1_imag + Aik1_imag * Bjk1_real) + (Bik1_real * Ajk1_imag + Bik1_imag * Ajk1_real);
                }
            }
        }
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp_real - alpha_imag * temp_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp_imag + alpha_imag * temp_real;
    }
}
}
