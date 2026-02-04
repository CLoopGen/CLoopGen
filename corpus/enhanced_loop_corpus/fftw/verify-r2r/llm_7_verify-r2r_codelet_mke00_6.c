#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *a;
extern int n;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    bench_real temp;
    for (i = 1; i + i < n; ++i) {
        temp = a[i][c];           // Introduce temporary to create local RAW dependency
        a[n - i][c] = temp;       // Delayed store creates intra-iteration dependence, preserving semantics but altering data flow
    } // Loop-carried dependencies removed due to independent iterations, but intra-loop RAW introduced via 'temp'
}
