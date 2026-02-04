#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the loop order
    // We traverse column-major but reorganize to access C in a more consecutive pattern along columns
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {
            C[ldc * i + j] *= beta;
        }
    }
}
