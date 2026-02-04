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
    R xr = ((a[i])[0]), xi = ((a[i])[1]);
    R alpha_r = ((alpha)[0]), alpha_i = ((alpha)[1]);
    R temp_r = xr * alpha_r - xi * alpha_i;
    R temp_i = xr * alpha_i + xi * alpha_r;
    ((a[i])[0]) = temp_r;
    ((a[i])[1]) = temp_i;
    ((a[i])[0]) = temp_r * alpha_r - temp_i * alpha_i;
    ((a[i])[1]) = temp_r * alpha_i + temp_i * alpha_r;
}
}
