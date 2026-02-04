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
    // Variant 2: Strided memory access with reversed inner loop to traverse column-like pattern
    double *C_base = (double *)C;
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {  // Transposed iteration bounds to maintain same set of indices
            int linear_offset = 2 * (ldc * i + j);
            C_base[linear_offset]     = 0.;
            C_base[linear_offset + 1] = 0.;
        }
    }
}
