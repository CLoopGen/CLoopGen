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
    int j;
    for (j = 0; j < 1; ++j) {
        ((A[i])[0]) = ((x)[0]);
        ((A[i])[1]) = ((x)[1]);
    }
}
}
