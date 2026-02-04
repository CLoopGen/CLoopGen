#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with fixed stride
    // We traverse the matrix in a strided pattern across rows, writing every ldc-th element
    double *pC;
    for (i = 0; i < N; i++) {
        pC = &C[ldc * i];  // Base pointer for row i
        for (j = 0; j <= i; j++) {
            *(pC + j) = 0.;  // Still accesses consecutive elements in row, but uses pointer arithmetic
        }
    }
}
