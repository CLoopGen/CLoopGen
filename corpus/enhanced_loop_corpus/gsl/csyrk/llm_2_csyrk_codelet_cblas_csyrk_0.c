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
    // Variant 1: Consecutive memory access by flattening the 2D index and accessing elements in row-major order
    float *C_ptr = (float *)C;
    int offset = 0;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            offset = 2 * (ldc * i + j);
            C_ptr[offset] = 0.;
            C_ptr[offset + 1] = 0.;
        }
    }
}
