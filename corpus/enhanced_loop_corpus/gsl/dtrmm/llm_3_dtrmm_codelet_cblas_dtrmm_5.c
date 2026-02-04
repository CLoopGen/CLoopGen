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
for (j = 0; j < n2; j++) {
    int aj_offset = j * lda;
    int col_start_B = j;
    for (i = 0; i < n1; i++) {
        double temp = 0.;
        int row_B = i * ldb;
        if (nonunit) {
            temp = A[aj_offset + j] * B[row_B + j];
        } else {
            temp = B[row_B + j];
        }
        for (k = j + 1; k < n2; k++) {
            temp += A[aj_offset + k] * B[row_B + k];
        }
        B[row_B + j] = alpha * temp;
    }
}
}
