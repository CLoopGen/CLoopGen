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
    // Variant 1: Consecutive memory access by transposing the loop order to access C in row-major like fashion
    // We reverse iteration order to enable sequential writes when ldc is large, using pointer arithmetic for direct traversal
    float *base = C;
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {
            base[ldc * i + j] *= beta;
        }
    }
}
