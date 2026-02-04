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
    // Variant 1: Consecutive memory access by flattening the 2D index and accessing elements in increasing order
    double *C_ptr = (double *)C;
    int total_elements = ldc * N;  // Assuming C is at least this large
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            int idx = 2 * (ldc * i + j);
            C_ptr[idx] = 0.;
            C_ptr[idx + 1] = 0.;
        }
    }
}
