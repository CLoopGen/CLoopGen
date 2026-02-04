#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Use a base pointer per row and stride through with fixed increments
    // This emphasizes strided access patterns that might be relevant in blocked or padded layouts
    float *base;
    int stride = ldc;
    for (i = 0; i < N; i++) {
        base = &C[ldc * i];  // Base of row i
        for (j = 0; j <= i; j++) {
            *(base + j) = 0.;  // Unit stride access from base
        }
    }
}
