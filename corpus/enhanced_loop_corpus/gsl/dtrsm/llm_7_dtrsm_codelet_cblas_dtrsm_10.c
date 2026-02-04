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
    double temp_Bj[n2]; // Introduce local accumulation to alter data dependencies
    // First pass: read and scale B[i][j] values without writing back
    for (j = n2 - 1; j >= 0; j--) {
        if (nonunit) {
            double Ajj = A[lda * j + j];
            temp_Bj[j] = B[ldb * i + j] / Ajj;
        } else {
            temp_Bj[j] = B[ldb * i + j];
        }
    }
    // Second pass: update B[i][k] using cached values to eliminate write-read dependency in inner loop
    for (j = n2 - 1; j >= 0; j--) {
        double Bij = temp_Bj[j];
        for (k = 0; k < j; k++) {
            B[ldb * i + k] -= A[k * lda + j] * Bij;
        }
    }
}
}
