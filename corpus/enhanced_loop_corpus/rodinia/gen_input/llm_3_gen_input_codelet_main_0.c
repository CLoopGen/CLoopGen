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
    for (k = 0; k < MatrixDim; k++) {
        FP_NUMBER temp = L[i][k];
        for (j = 0; j < MatrixDim; j++)
            A[i][j] += temp * U[k][j];
    }
}
}
