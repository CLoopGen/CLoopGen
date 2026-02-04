#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *A;
extern  int lda;
extern double *B;
extern  int ldb;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern  int nonunit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double temp_sum = 0.0;
        if (nonunit) {
            double Ajj = A[lda * j + j];
            B[ldb * i + j] /= Ajj;
        }
        for (k = j + 1; k < n2; k++) {
            temp_sum += A[j * lda + k] * B[ldb * i + j];
            B[ldb * i + k] -= A[j * lda + k] * B[ldb * i + j];
        }
        // Introduce artificial WAW and WAR dependency via temp_sum (used but not changing logic)
        temp_sum += temp_sum;
    }
}
}
