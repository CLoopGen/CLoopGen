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
    // Variant 1: Consecutive memory access by precomputing base pointer and using linear index
    float *C_ptr = (float *)C;
    int idx = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            idx = 2 * (ldc * i + j);
            C_ptr[idx] = 0.;
            C_ptr[idx + 1] = 0.;
        }
    }
}
