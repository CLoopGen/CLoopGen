#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

extern bench_real *A;
extern int n;
extern bench_real x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; ++j)
    for (i = 0; i < n; ++i)
        A[i] = x;
}
