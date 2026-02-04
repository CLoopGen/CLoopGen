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
for (i = 0; i < n1; i++) {
    double temp_accum_real[64]; // Local blocking buffer to change data reuse pattern
    double temp_accum_imag[64];
    for (j = 0; j < n2; j++) {
        // Initialize per-j accumulators early to introduce WAR dependency resolution via renaming
        temp_accum_real[j & 63] = 0.0;
        temp_accum_imag[j & 63] = 0.0;
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;
        // Reverse loop order to modify loop-carried RAW dependencies
        for (k = j - 1; k >= 0; k--) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);
            // Update C using reversed access but accumulate temp2 forward logically
            (((double *)C)[2 * (i * ldc + k)]) += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            (((double *)C)[2 * (i * ldc + k) + 1]) += temp1_real * Ajk_imag + temp1_imag * Ajk_real;
            temp2_real += Bik_real * Ajk_real - Bik_imag * Ajk_imag;
            temp2_imag += Bik_real * Ajk_imag + Bik_imag * Ajk_real;
        }
        {
            const double Ajj_real = (((const double *)A)[2 * (j * lda + j)]);
            const double Ajj_imag = (((const double *)A)[2 * (j * lda + j) + 1]);
            // Use temporary accumulator before final write to delay update (introduces artificial WAR)
            double new_val_real = temp1_real * Ajj_real - temp1_imag * Ajj_imag;
            double new_val_imag = temp1_real * Ajj_imag + temp1_imag * Ajj_real;
            temp_accum_real[j & 63] += new_val_real;
            temp_accum_imag[j & 63] += new_val_imag;
        }
        // Final update uses delayed values, changing write timing (WAW modified)
        (((double *)C)[2 * (i * ldc + j)]) += temp_accum_real[j & 63] + (alpha_real * temp2_real - alpha_imag * temp2_imag);
        (((double *)C)[2 * (i * ldc + j) + 1]) += temp_accum_imag[j & 63] + (alpha_real * temp2_imag + alpha_imag * temp2_real);
    }
}
}
