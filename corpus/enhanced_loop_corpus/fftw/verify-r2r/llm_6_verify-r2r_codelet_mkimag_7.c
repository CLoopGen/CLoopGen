#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *a;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    bench_real sum = 0.0;
    for (i = 0; i < n; ++i) {
        sum += ((a[i])[0]);
        ((a[i])[0]) = 0.;
    }
    // Introduces a loop-carried dependency (sum depends on previous iteration)
    // RAW dependency: sum read before write in each iteration
    // Still initializes a[i][0] to 0, but with an accumulated data flow
}
