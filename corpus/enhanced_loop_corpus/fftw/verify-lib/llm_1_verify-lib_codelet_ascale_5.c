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
    int stride = 4;
    for (i = 0; i < n; i += stride) {
        for (int k = 0; k < stride && (i + k) < n; ++k) {
            int idx = i + k;
            R xr = ((a[idx])[0]), xi = ((a[idx])[1]);
            ((a[idx])[0]) = xr * ((alpha)[0]) - xi * ((alpha)[1]);
            ((a[idx])[1]) = xr * ((alpha)[1]) + xi * ((alpha)[0]);
        }
    }
}
