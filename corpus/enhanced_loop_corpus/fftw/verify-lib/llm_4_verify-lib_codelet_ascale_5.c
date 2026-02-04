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
    for (i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            R xr = ((a[i])[0]), xi = ((a[i])[1]);
            ((a[i])[0]) = xr * ((alpha)[0]) - xi * ((alpha)[1]);
            ((a[i])[1]) = xr * ((alpha)[1]) + xi * ((alpha)[0]);
        }
    }
}
