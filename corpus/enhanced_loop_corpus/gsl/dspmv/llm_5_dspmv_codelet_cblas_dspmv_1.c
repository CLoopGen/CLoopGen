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
    for (i = 0; i < N; i++) {
        if (Y[iy] != 0.0) {
            Y[iy] *= beta;
        } else {
            Y[iy] = beta;
        }
        iy += incY;
    }
}
