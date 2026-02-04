#include <stdio.h>

#include <inttypes.h>

extern int nr;
extern int nq;
extern int np;
extern double A[150][140][160];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < nr; i++)
    for (j = 1; j < nq; j++)
        for (k = 1; k < np; k++)
            A[i][j][k] = (A[i-1][j][k] + A[i][j-1][k] + A[i][j][k-1]) / 3.0;
    // Introduce RAW (read-after-write) and loop-carried dependencies:
    // Each element depends on previously computed (spatially adjacent) elements.
    // This creates a true dependence where current iteration reads values written in prior iterations.
    // Dependency chain prevents parallelization across all loops.
}
