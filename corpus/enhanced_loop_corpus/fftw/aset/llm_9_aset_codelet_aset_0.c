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
    // Variant 2: Reduced trip count with stride-2 loop and conditional-like behavior using arithmetic
    // Effectively halves the number of iterations by processing every second element
    // Maintains loop structure but changes data access pattern and reduces overhead
    bench_real val = x;
    for (i = 0; i < n; i += 2) {
        A[i] = val;
        if (i + 1 < n) {
            A[i + 1] = val;
        }
    }
}
