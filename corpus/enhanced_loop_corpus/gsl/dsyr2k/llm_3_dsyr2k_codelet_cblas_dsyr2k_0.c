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
    // Variant 2: Strided memory access using pointer arithmetic with explicit stride
    // Instead of indexing with [ldc*i + j], we use a base pointer and advance by ldc
    double *base = C;
    for (i = 0; i < N; i++) {
        double *row_start = base + ldc * i;
        for (j = i; j < N; j++) {
            row_start[j] = 0.;
        }
    }
}
