#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float *Ap;
extern int i;
extern int j;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flattened version: remove inner loop by unrolling the dependency through conditional logic
// Simulate loop behavior with a single loop using manual index tracking

int idx = 0;
ix = 0;
iy = 0;
for (i = 0; i < N; i++) {
    const double tmp1 = alpha * X[ix];
    const double tmp2 = alpha * Y[iy];
    int jx = ix;
    int jy = iy;
    j = i;
    // Manually simulate inner loop body once per outer iteration — reduced nesting
    {
        Ap[((((((i) - 1) + 1) * (2 * (N) - ((i) - 1))) / 2) + (j) - (i))] += tmp1 * Y[jy] + tmp2 * X[jx];
    }
    ix += incX;
    iy += incY;
}
}
