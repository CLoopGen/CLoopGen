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
    // Variant 2: Strided Memory Access Pattern
    // Introduce explicit strided access for both Ap and X arrays.
    // Use a fixed stride multiplier to simulate non-unit stride access,
    // which may model blocked or interleaved data layouts.

    const int STRIDE_A = 1;  // Base stride remains 1 but expressed explicitly
    const int STRIDE_X = abs(incX);  // Use absolute incX as effective stride
    int stride_offset_A = 0;
    int stride_offset_X = 0;

    for (i = N; i > 0 && i--;) {
        // Convert Ap access to use explicit strided formula for lower triangular
        stride_offset_A = (((i + 1) * (2 * N - i)) / 2) - 1; // Simplified index
        float atmp = Ap[stride_offset_A * STRIDE_A];
        float temp = (nonunit ? X[ix * STRIDE_X] * atmp : X[ix * STRIDE_X]);

        int jx = ((incX) > 0 ? 0 : (N - 1) * (-incX));
        for (j = 0; j < i; j++) {
            stride_offset_A = (((j + 1) * (2 * N - j)) / 2) + (i - j) - 1;
            atmp = Ap[stride_offset_A * STRIDE_A];
            temp += atmp * X[jx * STRIDE_X];
            jx += incX;
        }
        X[ix * STRIDE_X] = temp;
        ix -= incX;
    }
}
