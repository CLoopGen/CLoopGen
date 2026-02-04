#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nk;
extern double B[1000][900];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependencies by reordering computations and using temporary variables.
// Also remove potential RAW hazards by decoupling reads from previous writes in the same loop.
double temp;
for (i = 0; i < nk; i++) {
    for (j = 0; j < nj; j++) {
        temp = (double)((i * (j + 1) + 2) % nj) / (5 * nj);
        B[i][j] = temp;
    }
}
// Further optimize by unrolling the inner loop once to expose parallelism and reduce loop overhead.
for (i = 0; i < nk; i++) {
    for (j = 0; j < nj - 1; j += 2) {
        B[i][j]   = (double)((i * (j + 1) + 2) % nj) / (5 * nj);
        B[i][j+1] = (double)((i * (j + 2) + 2) % nj) / (5 * nj);
    }
    // Handle odd nj case
    if (j == nj - 1)
        B[i][j] = (double)((i * (j + 1) + 2) % nj) / (5 * nj);
}
}
