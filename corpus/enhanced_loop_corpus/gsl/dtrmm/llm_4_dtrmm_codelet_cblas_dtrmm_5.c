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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double temp = B[i * ldb + j]; // Initialize with B value unconditionally
        if (nonunit) {
            temp = A[j * lda + j] * temp; // Apply diagonal scaling only if nonunit
        }
        for (k = j + 1; k < n2; k++) {
            temp += A[lda * j + k] * B[i * ldb + k];
        }
        B[ldb * i + j] = alpha * temp;
    }
}
}
