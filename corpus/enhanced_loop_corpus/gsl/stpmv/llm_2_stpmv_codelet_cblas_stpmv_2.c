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
    // Variant 1: Consecutive Memory Access Pattern
    // Modified to access Ap and X with consecutive indices by precomputing offsets
    // and using a forward iteration pattern for better cache locality.

    int base_idx = 0;
    int offset = 0;
    float *ap_base = Ap;
    float *x_base = X;

    for (i = 0; i < N; i++) {
        // Compute triangular matrix offset for lower triangle storage: row i, column i
        offset = (i * (2 * N - i + 1)) / 2;
        float atmp = ap_base[offset];
        float temp = (nonunit ? x_base[ix] * atmp : x_base[ix]);

        int jx = (incX > 0 ? 0 : (N - 1) * (-incX));
        for (j = 0; j < i; j++) {
            // Update Ap access to use consecutive row-major-like indexing
            int ap_index = (j * (2 * N - j + 1)) / 2 + (i - j);
            atmp = ap_base[ap_index];
            temp += atmp * x_base[jx];
            jx += incX;
        }
        x_base[ix] = temp;
        ix -= incX;
    }
}
