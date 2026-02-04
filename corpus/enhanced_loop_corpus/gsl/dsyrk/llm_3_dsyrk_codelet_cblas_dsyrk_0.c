#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with stride equal to ldc
    double *base_C = C;
    for (i = 0; i < N; i++) {
        double *row_start = base_C + ldc * i;
        for (j = i; j < N; j++) {
            *(row_start + j) = 0.;  // Equivalent to C[ldc*i + j], but emphasizes strided access
        }
    }
}
