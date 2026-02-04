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
    // Variant 2: Strided memory access with reversed loop order to create non-unit stride and different traversal pattern
    double *C_ptr = (double *)C;
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {  // Transposed logic: now iterating over upper triangle via column-major-like access
            int offset = 2 * (ldc * i + j);
            C_ptr[offset] = 0.;
            C_ptr[offset + 1] = 0.;
        }
    }
}
