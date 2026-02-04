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
    // Variant 2: Strided memory access with column-major traversal and stride over rows
    // Simulates a strided access pattern where each iteration jumps by ldc in the inner dimension
    double *C_ptr = (double *)C;
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            int base_offset = 2 * (ldc * i + j);
            C_ptr[base_offset]     = 0.;
            C_ptr[base_offset + 1] = 0.;
        }
    }
}
