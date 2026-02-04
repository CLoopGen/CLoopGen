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
for (i = 0; i < n; ++i)
    ((a[i])[0]) = 0.;

}
