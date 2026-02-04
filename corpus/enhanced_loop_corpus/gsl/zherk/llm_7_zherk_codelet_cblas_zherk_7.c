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
// Reverse loop order to change data access pattern and eliminate some forward dependencies
// Now we traverse i and j in reverse, modifying the loop bounds accordingly
for (i = N - 1; i >= 0; i--) {
    for (j = i; j >= 0; j--) {
        double temp_real = 0.;
        double temp_imag = 0.;
        // Reorder inner loop to accumulate from last to first — changes floating-point rounding behavior slightly but preserves semantics
        for (k = K - 1; k >= 0; k--) {
            const double Aik_real = (((const double *)A)[2 * (i * lda + k)]);
            const double Aik_imag = (((const double *)A)[2 * (i * lda + k) + 1]);
            const double Ajk_real = (((const double *)A)[2 * (j * lda + k)]);
            const double Ajk_imag = -(((const double *)A)[2 * (j * lda + k) + 1]);
            temp_real += Aik_real * Ajk_real - Aik_imag * Ajk_imag;
            temp_imag += Aik_real * Ajk_imag + Aik_imag * Ajk_real;
        }
        // Update C with computed values — write still happens once per (i,j), no interference due to reversed index access
        (((double *)C)[2 * (i * ldc + j)]) += alpha * temp_real;
        (((double *)C)[2 * (i * ldc + j) + 1]) += alpha * temp_imag;
    }
}
}
