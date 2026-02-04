#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use consecutive memory access by transposing the iteration order where possible
    // Instead of row-major with triangular bounds, iterate column-wise within lower triangle
    // This improves spatial locality for column-major layout if ldc is large
    int jj, ii;
    for (jj = 0; jj < N; jj++) {
        for (ii = jj; ii < N; ii++) {
            C[ldc * ii + jj] *= beta;
        }
    }
}
