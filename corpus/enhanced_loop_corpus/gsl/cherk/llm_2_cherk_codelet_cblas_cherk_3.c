#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing elements in natural order, traverse C with a fixed stride
    // Here, we process two elements at a time but with a precomputed base index to simulate strided access patterns
    int idx;
    for (i = 0; i < N; i++) {
        idx = 2 * ldc * i; // Base offset scaled by 2 for complex float (real/imag)
        for (j = 0; j < i; j++) {
            int col_offset = 2 * j;
            (((float *)C)[idx + col_offset]) *= beta;
            (((float *)C)[idx + col_offset + 1]) *= beta;
        }
        // Diagonal element handling remains separate due to assignment to 0
        (((float *)C)[idx + 2 * i]) *= beta;
        (((float *)C)[idx + 2 * i + 1]) = 0;
    }
}
