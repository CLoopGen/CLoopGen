#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

typedef bench_real R;

extern C *a;
extern C alpha;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    bench_real alpha0 = (alpha)[0];
    bench_real alpha1 = (alpha)[1];
    for (i = 0; i < n; ++i) {
        R xr = ((a[i])[0]), xi = ((a[i])[1]);
        ((a[i])[0]) = xr * alpha0 - xi * alpha1;
        ((a[i])[1]) = xr * alpha1 + xi * alpha0;
    }
}
