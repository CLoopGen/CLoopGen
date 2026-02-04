#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
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
for (i = 0; i < n1; i++) {
    float temp_store[512]; // Assuming n2 is reasonably small, otherwise dynamic allocation needed
    float diag_val = nonunit ? A[i * lda + i] : 0.0f;

    for (j = 0; j < n2; j++) {
        temp_store[j] = nonunit ? diag_val * B[i * ldb + j] : B[i * ldb + j];
    }

    for (k = i + 1; k < n1; k++) {
        float a_val = A[lda * k + i];
        for (j = 0; j < n2; j++) {
            temp_store[j] += a_val * B[k * ldb + j];
        }
    }

    for (j = 0; j < n2; j++) {
        B[ldb * i + j] = alpha * temp_store[j];
    }
}
}
