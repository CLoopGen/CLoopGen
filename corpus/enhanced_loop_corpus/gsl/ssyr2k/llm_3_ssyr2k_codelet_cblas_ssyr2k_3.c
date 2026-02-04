#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with step size ldc
    // We use a base pointer for each row and step through with fixed stride
    float *base_C;
    for (i = 0; i < N; i++) {
        base_C = &C[ldc * i];  // Base of row i
        for (j = 0; j <= i; j++) {
            base_C[j] *= beta;  // Now accessing base_C with consecutive offsets
        }
    }
}
