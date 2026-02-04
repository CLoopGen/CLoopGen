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
    bench_real local_accum = x;
    for (i = 1; i < n; ++i) {
        A[i] = local_accum;
        local_accum += x; // Remove direct WAW and introduce non-carried dependency via local scalar evolution
    }
    if (n > 0)
        A[0] = x; // Ensure full coverage; eliminate loop-carried dependency by reordering and splitting
}
