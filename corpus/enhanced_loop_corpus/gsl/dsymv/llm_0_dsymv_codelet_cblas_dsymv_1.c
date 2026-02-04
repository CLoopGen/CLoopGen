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
    int i_outer, i_inner;
    for (i_outer = 0; i_outer < N; i_outer++) {
        for (i_inner = 0; i_inner < 1; i_inner++) {
            Y[iy] *= beta;
            iy += incY;
        }
    }
}
