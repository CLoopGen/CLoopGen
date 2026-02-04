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
    // Reverse the j-loop to introduce loop-carried dependency in reverse order
    // This changes data reuse pattern and introduces different cache behavior
    for (j = n2 - 1; j >= 0; j--) {
        const double Bij_real = (((const double *)B)[2 * (ldb * i + j)]);
        const double Bij_imag = (((const double *)B)[2 * (ldb * i + j) + 1]);
        const double temp1_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const double temp1_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        double temp2_real = 0.;
        double temp2_imag = 0.;

        // Modify loop bounds and access patterns to eliminate some RAW hazards
        // by ensuring k runs from j+1 to n2, changing dependency structure
        for (k = j + 1; k < n2; k++) {
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = (((const double *)A)[2 * (j * lda + k) + 1]);
            const double Bik_real = (((const double *)B)[2 * (ldb * i + k)]);
            const double Bik_imag = (((const double *)B)[2 * (ldb * i + k) + 1]);

            // Update C with reversed indexing logic — now writing ahead in k
            (((double *)C)[2 * (i * ldc + k)]) += temp1_real * Ajk_real - temp1_imag * Ajk_imag;
            (((double *)C)[2 * (i * ldc + k) + 1]) += temp1_real * Ajk_imag + temp1_imag * Ajk_real;

            temp2_real += Bik_real * Ajk_real - Bik_imag * (-Ajk_imag);
            temp2_imag += Bik_real * (-Ajk_imag) + Bik_imag * Ajk_real;
        }
        // Update diagonal element using same formula but now safe due to reversed loop
        {
            const double Ajj_real = (((const double *)A)[2 * (j * lda + j)]);
            (((double *)C)[2 * (i * ldc + j)]) += temp1_real * Ajj_real;
            (((double *)C)[2 * (i * ldc + j) + 1]) += temp1_imag * Ajj_real;
        }
        // Final update to C[j] includes contribution from future k-values (now past due to reverse)
        (((double *)C)[2 * (i * ldc + j)]) += alpha_real * temp2_real - alpha_imag * temp2_imag;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha_real * temp2_imag + alpha_imag * temp2_real;
    }
}
}
