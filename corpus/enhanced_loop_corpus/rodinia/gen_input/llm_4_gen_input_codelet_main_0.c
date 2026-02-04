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
        for (k = 0; k < MatrixDim; k++) {
            if (L[i][k] != 0 && U[k][j] != 0) {
                sum += L[i][k] * U[k][j];
            }
        }
        A[i][j] = sum;
    }
}
}
