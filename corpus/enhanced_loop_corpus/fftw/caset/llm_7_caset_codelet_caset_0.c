#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

extern bench_complex *A;
extern int n;
extern bench_complex x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; ++i) {
        bench_real val0 = (x)[0] + (A[i])[0]; // Introduce RAW: read A[i] before write
        bench_real val1 = (x)[1] + (A[i])[1];
        ((A[i])[0]) = val0;
        ((A[i])[1]) = val1;
    }
}
