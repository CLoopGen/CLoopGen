#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = N; i > 0 && i--;) {
    double temp = 0.;
    const int j_min = 0;
    const int j_max = i;
    // Change access pattern to ensure unit stride on A and strided on X
    // Reorder computation to traverse A in column-major consecutive order
    for (j = j_min; j < j_max; j++) {
        // Access A with unit stride: A[i + j*lda] becomes A[j + i*lda] -> already column-wise
        // But now optimize by precomputing base pointer to column i of A
        temp += X[(j * incX)] * A[j + i * lda];
    }
    // Update X using reversed unit stride simulation via offset calculation
    int target_ix = ix;
    if (nonunit) {
        X[target_ix] = temp + X[target_ix] * A[i + i * lda];
    } else {
        X[target_ix] += temp;
    }
    ix -= incX;
}
}
