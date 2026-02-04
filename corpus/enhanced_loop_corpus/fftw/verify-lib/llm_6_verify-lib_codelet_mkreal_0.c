#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *A;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    bench_real sum = 0.0;
    for (i = 0; i < n; ++i) {
        sum += ((A[i])[1]);
        ((A[i])[1]) = 0.;
    }
    // Introduces a loop-carried flow dependency (sum depends on previous iteration)
    // RAW dependency within the loop: sum read after write from prior iteration
    // Still correctly initializes A[i][1] to 0, with added reduction-like accumulation
}
