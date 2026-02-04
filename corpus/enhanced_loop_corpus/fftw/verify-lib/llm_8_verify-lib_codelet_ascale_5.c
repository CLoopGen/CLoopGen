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
for (i = 0; i < n; i += 2) {
    R xr0 = ((a[i])[0]), xi0 = ((a[i])[1]);
    R xr1 = ((a[i+1])[0]), xi1 = ((a[i+1])[1]);
    ((a[i])[0]) = xr0 * ((alpha)[0]) - xi0 * ((alpha)[1]);
    ((a[i])[1]) = xr0 * ((alpha)[1]) + xi0 * ((alpha)[0]);
    ((a[i+1])[0]) = xr1 * ((alpha)[0]) - xi1 * ((alpha)[1]);
    ((a[i+1])[1]) = xr1 * ((alpha)[1]) + xi1 * ((alpha)[0]);
}
}
