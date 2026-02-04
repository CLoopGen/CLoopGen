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
    // Variant 1: Consecutive memory access by unrolling and accessing adjacent elements together
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            int64_t base_idx = 2 * (ldc * i + j);
            double* c_ptr = &((double*)C)[base_idx];
            c_ptr[0] = 0.;
            c_ptr[1] = 0.;
        }
    }
}
