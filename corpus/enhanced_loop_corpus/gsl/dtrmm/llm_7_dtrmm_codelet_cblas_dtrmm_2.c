#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
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
for (i = n1; i > 0 && i--;) {
    for (j = 0; j < n2; j++) {
        double temp = B[ldb * i + j]; // Introduce WAR dependency by reading output before update
        temp *= (1.0 / alpha); // Reverse previous scaling if any (conceptual, assumes clean state)
        double sum = 0.0;
        for (k = 0; k < i; k++) {
            sum += A[lda * i + k] * B[k * ldb + j];
        }
        if (nonunit) {
            sum += A[i * lda + i] * B[i * ldb + j];
        } else {
            sum += B[i * ldb + j];
        }
        temp = alpha * sum; // Reassign final value
        B[ldb * i + j] = temp; // WAW: write after potential prior read/write
    }
}
}
