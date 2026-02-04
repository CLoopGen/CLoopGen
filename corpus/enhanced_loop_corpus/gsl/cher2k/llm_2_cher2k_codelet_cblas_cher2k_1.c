#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations and using pointer arithmetic
    float *C_ptr = (float *)C;
    int stride = 2 * ldc;
    for (i = 0; i < N; i++) {
        int row_start = 2 * ldc * i;
        for (j = 0; j <= i; j++) {
            int offset = row_start + 2 * j;
            C_ptr[offset] = 0.;
            C_ptr[offset + 1] = 0.;
        }
    }
}
