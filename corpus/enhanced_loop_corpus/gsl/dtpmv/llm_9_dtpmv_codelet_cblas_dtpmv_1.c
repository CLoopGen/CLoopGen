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
    // Variant 2: Reduced trip count and simplified computation by skipping every other outer iteration.
    // This decreases total work and modifies data access pattern to lower computational load.
    // Outer loop runs approximately half as many times.
    for (i = N; i > 1 && i--; i--) {  // Decrement by 2 effectively via two decrements
        double atmp = Ap[(((i) * ((i) + 1)) / 2 + (i))];
        double temp = (nonunit ? X[ix] * atmp : X[ix]);
        int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
        // Inner loop processes only even indices
        for (j = 0; j < i; j += 2) {
            atmp = Ap[(((i) * ((i) + 1)) / 2 + j)];
            temp += atmp * X[jx];
            jx += incX * 2;
        }
        X[ix] = temp;
        ix -= incX;
        // Skip next outer iteration index
        if (i <= 1) break;
        i--;
        // Also skip corresponding vector index update
        if (ix >= 0 && ix < N) ix -= incX;
    }
}
