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
    bench_real temp0 = (x)[0];
    bench_real temp1 = (x)[1];
    for (i = 0; i < n; ++i) {
        ((A[i])[0]) = temp0;
        ((A[i])[1]) = temp1;
    }
}
