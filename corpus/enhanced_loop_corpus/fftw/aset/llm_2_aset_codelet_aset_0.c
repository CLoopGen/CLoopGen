#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

extern bench_real *A;
extern int n;
extern bench_real x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then the rest)
    int stride = 2;
    for (i = 0; i < n; i += stride)
        A[i] = x;
    for (i = 1; i < n; i += stride)
        A[i] = x;
}
