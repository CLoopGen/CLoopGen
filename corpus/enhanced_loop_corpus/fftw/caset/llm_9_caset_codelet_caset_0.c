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
    bench_real factor = 1.5;
    for (i = 0; i < n; ++i) {
        ((A[i])[0]) = ((x)[0]) * factor + ((x)[1]) * 0.1;
        ((A[i])[1]) = ((x)[1]) * factor - ((x)[0]) * 0.1;
    }
}
