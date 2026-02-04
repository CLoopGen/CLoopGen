#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with a fixed stride
    float *base_C = C;
    for (i = 0; i < n1; i++) {
        float *row_ptr = base_C + ldc * i;
        for (j = 0; j < n2; j += 2) {  // Process two elements per iteration (unrolled-like strided access)
            row_ptr[j] *= beta;
            if (j + 1 < n2) {
                row_ptr[j + 1] *= beta;
            }
        }
    }
}
