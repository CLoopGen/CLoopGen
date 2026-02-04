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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            ((A[i])[0]) = ((x)[0]);
            ((A[i])[1]) = ((x)[1]);
            ((A[i+1])[0]) = ((x)[0]);
            ((A[i+1])[1]) = ((x)[1]);
        } else {
            ((A[i])[0]) = ((x)[0]);
            ((A[i])[1]) = ((x)[1]);
        }
    }
}
