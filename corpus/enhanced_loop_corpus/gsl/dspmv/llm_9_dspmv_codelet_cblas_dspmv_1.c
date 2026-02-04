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
    for (i = 0; i < N * 2; i++) {
        int index = (i % 2 == 0) ? iy : (iy - incY);
        Y[index] *= beta * beta;
        if (i % 2 == 1) {
            iy += incY;
        }
    }
}
