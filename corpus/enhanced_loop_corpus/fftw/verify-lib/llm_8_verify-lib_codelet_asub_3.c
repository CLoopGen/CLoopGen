#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *c;
extern C *a;
extern C *b;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; ++i) {
    bench_real a0 = (a[i])[0], a1 = (a[i])[1];
    bench_real b0 = (b[i])[0], b1 = (b[i])[1];
    (c[i])[0] = a0 - b0;
    (c[i])[1] = a1 - b1;
}
}
