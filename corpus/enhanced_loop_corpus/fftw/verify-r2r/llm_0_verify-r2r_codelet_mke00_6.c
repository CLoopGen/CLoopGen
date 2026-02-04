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
    for (i = 1; i + i < n; ++i)
        for (int j = 0; j < c; ++j)
            a[n - i][j] = a[i][j];
}
