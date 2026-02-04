#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *Ap;
extern float *X;
extern  int incX;
extern int i;
extern int j;
extern  int nonunit;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern for Ap by precomputing indices and using a flat traversal
    // We assume Ap stores lower triangular matrix in packed format; here we maintain logical correctness
    // but reorganize access to Ap to be more sequential where possible.
    for (i = 0; i < N; i++) {
        int idx_diag = (i * (i + 1)) / 2 + i;
        float atmp = Ap[idx_diag];
        float temp = (nonunit ? X[ix] * atmp : X[ix]);
        int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX)) + (i + 1) * incX;

        // Access Ap in increasing index order (consecutive in memory)
        for (j = i + 1; j < N; j++) {
            int idx = (j * (j + 1)) / 2 + i;  // Row j, column i in packed lower triangular
            temp += Ap[idx] * X[jx];
            jx += incX;
        }
        X[ix] = temp;
        ix += incX;
    }
}
