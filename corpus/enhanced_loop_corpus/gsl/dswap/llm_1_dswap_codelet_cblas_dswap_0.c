#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = N / 2;
    int inner = 2;
    int i, o, idx_x = ix, idx_y = iy;
    for (o = 0; o < outer; o++) {
        for (i = 0; i < inner; i++) {
            const double tmp = X[idx_x];
            X[idx_x] = Y[idx_y];
            Y[idx_y] = tmp;
            idx_x += incX;
            idx_y += incY;
        }
    }
    // Handle remainder if N is odd
    if (N % 2 != 0) {
        const double tmp = X[ix + N - 1];
        X[ix + N - 1] = Y[iy + N - 1];
        Y[iy + N - 1] = tmp;
    }
}
