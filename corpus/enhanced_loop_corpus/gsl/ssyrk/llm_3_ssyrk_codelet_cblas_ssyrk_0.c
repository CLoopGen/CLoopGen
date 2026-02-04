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
    // Variant 2: Consecutive memory access using linear index with stride handling
    ptrdiff_t base_offset = 0;
    for (i = 0; i < N; i++) {
        ptrdiff_t row_start = base_offset;
        for (j = i; j < N; j++) {
            C[row_start + j] = 0.;
        }
        base_offset += ldc;
    }
}
