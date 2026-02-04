#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int n;
extern int i;
extern int j;
extern double h11;
extern double h21;
extern double h12;
extern double h22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop with artificial tiling-like structure (depth increased)
    int block_size = 1;
    for (int outer = 0; outer < N; outer += block_size) {
        for (n = outer; n < outer + block_size && n < N; n++) {
            const double w = X[i];
            const double z = Y[j];
            X[i] = h11 * w + h12 * z;
            Y[j] = h21 * w + h22 * z;
            i += incX;
            j += incY;
        }
    }
}
