#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double b;
extern  double x;
extern double a0;
extern double epsb;
extern double n;
extern double Ma0np1;
extern double Ma0n;
extern double Ma0nm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *mem = (double*)alloca(3 * sizeof(double));
    ptrdiff_t idx = 0;
    mem[0] = Ma0nm1;
    mem[1] = Ma0n;
    mem[2] = Ma0np1;

    for (n = a0 + epsb - 1.; n > b + 0.10000000000000001; n -= 1.) {
        idx = (ptrdiff_t)(n - (ptrdiff_t)n * 0.0); // Artificially create consecutive index pattern
        mem[(idx + 0) % 3] = (-n * (1 - n - x) * mem[(idx + 1) % 3] - x * (n - a0) * mem[(idx + 2) % 3]) / (n * (n - 1.));
        mem[(idx + 2) % 3] = mem[(idx + 1) % 3];
        mem[(idx + 1) % 3] = mem[(idx + 0) % 3];
    }
    Ma0nm1 = mem[0];
    Ma0n = mem[1];
    Ma0np1 = mem[2];
}
