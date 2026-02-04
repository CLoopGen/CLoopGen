#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, outer;
    const int unroll_factor = 2;
    int remainder = N % unroll_factor;
    int limit = N - remainder;

    // Unrolled loop with increased depth via outer control and partial unrolling
    for (outer = 0; outer < limit; outer += unroll_factor) {
        for (i = outer; i < outer + unroll_factor; i++) {
            Y[iy] += alpha * X[ix];
            ix += incX;
            iy += incY;
        }
    }

    // Handle remaining iterations in a simple loop
    for (i = 0; i < remainder; i++) {
        Y[iy] += alpha * X[ix];
        ix += incX;
        iy += incY;
    }
}
