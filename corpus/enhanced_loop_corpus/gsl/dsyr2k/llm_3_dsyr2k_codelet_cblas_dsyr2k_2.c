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
    // Variant 2: Strided memory access using pointer arithmetic with stride ldc
    // Instead of indexed access, use pointers advanced by strides
    double *c_ptr = C;
    for (i = 0; i < N; i++) {
        c_ptr = C + ldc * i; // Point to start of row i
        for (j = i; j < N; j++) {
            *(c_ptr + j) *= beta; // Access with unit stride within row
        }
    }
}
