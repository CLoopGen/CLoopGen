#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *A;
extern  int lda;
extern float *B;
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
    if (nonunit) {
        float Aii = A[lda * i + i];
        for (j = 0; j < n2; j++) {
            B[ldb * i + j] /= Aii;
        }
    }
    // Introduce temporary array to break WAW and WAR dependencies
    // by accumulating updates in a local buffer before writing back.
    float temp[n2];
    for (j = 0; j < n2; j++) {
        temp[j] = 0.0f;
    }
    for (k = 0; k < i; k++) {
        const float Aki = A[k * lda + i];
        for (j = 0; j < n2; j++) {
            temp[j] += Aki * B[ldb * i + j];
        }
    }
    // Now apply accumulated subtractions to avoid repeated writes to B[ldb*k+j]
    for (k = 0; k < i; k++) {
        for (j = 0; j < n2; j++) {
            B[ldb * k + j] -= temp[j];
        }
    }
}
}
