#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < N; i += 2) {
        if (i + 0 < N) {
            Y[iy] = Y[iy] * beta + beta;
        }
        if (i + 1 < N) {
            Y[iy + incY] = Y[iy + incY] * beta + beta;
        }
        iy += 2 * incY;
    }
}
