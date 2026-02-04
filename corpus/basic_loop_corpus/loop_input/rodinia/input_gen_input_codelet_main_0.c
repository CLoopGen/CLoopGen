#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float FP_NUMBER;

int i;
int j;
int k;
int MatrixDim;
FP_NUMBER sum;
FP_NUMBER **L;
FP_NUMBER **U;
FP_NUMBER **A;

void init_vars() {
    MatrixDim = 512;

    L = (FP_NUMBER**)calloc(MatrixDim, sizeof(FP_NUMBER*));
    U = (FP_NUMBER**)calloc(MatrixDim, sizeof(FP_NUMBER*));
    A = (FP_NUMBER**)calloc(MatrixDim, sizeof(FP_NUMBER*));

    for (int idx = 0; idx < MatrixDim; idx++) {
        L[idx] = (FP_NUMBER*)calloc(MatrixDim, sizeof(FP_NUMBER));
        U[idx] = (FP_NUMBER*)calloc(MatrixDim, sizeof(FP_NUMBER));
        A[idx] = (FP_NUMBER*)calloc(MatrixDim, sizeof(FP_NUMBER));

        for (int jdx = 0; jdx < MatrixDim; jdx++) {
            L[idx][jdx] = (FP_NUMBER)(idx + jdx) / (MatrixDim * 0.5f);
            U[idx][jdx] = (FP_NUMBER)(idx - jdx) / (MatrixDim * 0.5f);
        }
    }

    sum = 0.0f;
}