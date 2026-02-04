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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Trip count remains the same, but each iteration performs more work (fused multiply-add with an extra operation)
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j += 2) {
            int index1 = ldc * i + j;
            int index2 = index1 + 1;

            C[index1] *= beta;
            C[index1] += beta;  // Additional arithmetic operation

            if (j + 1 < n2) {
                C[index2] *= beta;
                C[index2] += beta;  // Additional arithmetic operation
            }
        }
    }
}
