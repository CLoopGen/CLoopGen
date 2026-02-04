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
// Reverse loop iteration order to change data dependency pattern (reverse traversal)
// This introduces a different loop-carried dependence direction, processing from N-1 down to 1
int reversed_i;
int temp_ix = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX))) + (N - 1) * incX; // Set to last relevant element
for (reversed_i = N - 1; reversed_i >= 1; reversed_i--) {
    double tmp = X[temp_ix];
    int jx = ((incX) > 0 ? 0 : ((N) - 1) * (-(incX)));
    for (j = 0; j < reversed_i; j++) {
        // Recompute matrix access: same formula but with reversed_i
        const double Aji = Ap[((((((j) - 1) + 1) * (2 * (N) - ((j) - 1))) / 2) + (reversed_i) - (j))];
        tmp -= Aji * X[jx];
        jx += incX;
    }
    if (nonunit) {
        X[temp_ix] = tmp / Ap[((((((reversed_i) - 1) + 1) * (2 * (N) - ((reversed_i) - 1))) / 2) + (reversed_i) - (reversed_i))];
    } else {
        X[temp_ix] = tmp;
    }
    temp_ix -= incX; // Traverse backward along X
}
// Note: Original 'ix' is not used here due to reversed traversal; state of 'ix' after loop may differ
// Assumes that the access pattern remains valid under reverse processing (semantically acceptable if operations are associative and independent across iterations)
}
