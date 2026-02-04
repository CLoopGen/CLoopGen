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
double *temp_B = (double*)malloc(n1 * n2 * sizeof(double));
if (!temp_B) return;
int idx;
// Eliminate loop-carried WAW and WAR dependencies by using temporary storage
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double temp = 0.;
        idx = i * n2 + j;
        if (nonunit) {
            temp = A[i * lda + i] * B[i * ldb + j];
        } else {
            temp = B[i * ldb + j];
        }
        for (k = i + 1; k < n1; k++) {
            temp += A[lda * i + k] * B[k * ldb + j];
        }
        temp_B[idx] = alpha * temp;
    }
}
// Remove write-after-write (WAW) dependency on B by writing only once after full computation
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        B[i * ldb + j] = temp_B[i * n2 + j];
    }
}
free(temp_B);
}
