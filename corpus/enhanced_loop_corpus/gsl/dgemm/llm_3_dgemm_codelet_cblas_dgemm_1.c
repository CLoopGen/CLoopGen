#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with a fixed stride
    double *c_ptr = C;
    for (i = 0; i < n1; i++) {
        double *row_start = c_ptr + ldc * i;
        for (j = 0; j < n2; j++) {
            *(row_start + j) *= beta;
        }
    }
}
