#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *Ap;
extern double *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop twice and increasing arithmetic operations.
    // This reduces loop overhead and increases FLOPs per iteration, enhancing computational intensity.
    for (i = N; i > 0 && i--;) {
        double atmp = Ap[(((i) * ((i) + 1)) / 2 + (i))];
        double temp = (nonunit ? X[ix] * atmp : X[ix]);
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
        j = 0;
        // Unroll inner loop by factor of 2
        for (; j < i - 1; j += 2) {
            atmp = Ap[(((i) * ((i) + 1)) / 2 + j)];
            temp += atmp * X[jx];
            jx += incX;
            atmp = Ap[(((i) * ((i) + 1)) / 2 + j + 1)];
            temp += atmp * X[jx];
            jx += incX;
        }
        // Handle remaining element if any
        if (j < i) {
            atmp = Ap[(((i) * ((i) + 1)) / 2 + j)];
            temp += atmp * X[jx];
        }
        X[ix] = temp;
        ix -= incX;
    }
}
