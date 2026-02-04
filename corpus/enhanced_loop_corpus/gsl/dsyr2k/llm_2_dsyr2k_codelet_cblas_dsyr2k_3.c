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
    // Variant 1: Strided memory access with column-major traversal
    // Instead of row-wise (i-major) access, traverse by fixing j and striding through i
    for (j = 0; j < N; j++) {
        for (i = j; i < N; i++) {
            C[ldc * i + j] *= beta;
        }
    }
}
