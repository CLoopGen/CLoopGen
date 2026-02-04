#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FP_NUMBER;

extern int i;
extern int j;
extern int k;
extern int MatrixDim;
extern FP_NUMBER sum;
extern FP_NUMBER **L;
extern FP_NUMBER **U;
extern FP_NUMBER **A;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < MatrixDim; i++) {
    for (j = 0; j < MatrixDim; j++) {
        sum = 0;
        if (i % 2 == 0) {
            for (k = 0; k < MatrixDim; k++)
                sum += L[i][k] * U[k][j];
        } else {
            for (k = MatrixDim - 1; k >= 0; k--)
                sum += L[i][k] * U[k][j];
        }
        A[i][j] = sum;
    }
}
}
