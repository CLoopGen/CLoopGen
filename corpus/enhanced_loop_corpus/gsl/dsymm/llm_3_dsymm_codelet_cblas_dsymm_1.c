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
    // Variant 2: Strided memory access using pointer arithmetic with fixed stride (ldc) and local pointers
    double *c_ptr = C;
    for (i = 0; i < n1; i++) {
        double *c_row = c_ptr;
        for (j = 0; j < n2; j++) {
            *c_row *= beta;
            c_row += 1; // Access consecutive elements in row
        }
        c_ptr += ldc; // Move to next row with stride ldc
    }
}
