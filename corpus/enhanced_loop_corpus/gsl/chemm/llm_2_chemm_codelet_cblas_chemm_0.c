#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointer and using linear index
    float *C_ptr = (float *)C;
    int stride = 2 * ldc;
    for (i = 0; i < n1; i++) {
        int base_idx = 2 * i * ldc;
        for (j = 0; j < n2; j++) {
            int idx = base_idx + 2 * j;
            C_ptr[idx] = 0.;
            C_ptr[idx + 1] = 0.;
        }
    }
}
