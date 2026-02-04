#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern int conjF;
extern int conjG;
extern  float *F;
extern  float *G;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k += 2) {
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            float temp_real_0 = 0.0f, temp_imag_0 = 0.0f;
            float temp_real_1 = 0.0f, temp_imag_1 = 0.0f;
            int valid_0 = 0, valid_1 = 0;

            const float Fk0i_real = (((const float *)F)[2 * (ldf * k + i)]);
            const float Fk0i_imag = conjF * (((const float *)F)[2 * (ldf * k + i) + 1]);
            temp_real_0 = alpha_real * Fk0i_real - alpha_imag * Fk0i_imag;
            temp_imag_0 = alpha_real * Fk0i_imag + alpha_imag * Fk0i_real;
            valid_0 = !(temp_real_0 == 0.0f && temp_imag_0 == 0.0f);

            if (k + 1 < K) {
                const float Fk1i_real = (((const float *)F)[2 * (ldf * (k + 1) + i)]);
                const float Fk1i_imag = conjF * (((const float *)F)[2 * (ldf * (k + 1) + i) + 1]);
                temp_real_1 = alpha_real * Fk1i_real - alpha_imag * Fk1i_imag;
                temp_imag_1 = alpha_real * Fk1i_imag + alpha_imag * Fk1i_real;
                valid_1 = !(temp_real_1 == 0.0f && temp_imag_1 == 0.0f);
            }

            const float Gk0j_real = (((const float *)G)[2 * (ldg * k + j)]);
            const float Gk0j_imag = conjG * (((const float *)G)[2 * (ldf * k + j) + 1]);
            const float Gk1j_real = (k + 1 < K) ? (((const float *)G)[2 * (ldg * (k + 1) + j)]) : 0.0f;
            const float Gk1j_imag = (k + 1 < K) ? conjG * (((const float *)G)[2 * (ldg * (k + 1) + j) + 1]) : 0.0f;

            if (valid_0) {
                (((float *)C)[2 * (ldc * i + j)]) += temp_real_0 * Gk0j_real - temp_imag_0 * Gk0j_imag;
                (((float *)C)[2 * (ldc * i + j) + 1]) += temp_real_0 * Gk0j_imag + temp_imag_0 * Gk0j_real;
            }
            if (valid_1) {
                (((float *)C)[2 * (ldc * i + j)]) += temp_real_1 * Gk1j_real - temp_imag_1 * Gk1j_imag;
                (((float *)C)[2 * (ldc * i + j) + 1]) += temp_real_1 * Gk1j_imag + temp_imag_1 * Gk1j_real;
            }
        }
    }
}
}
