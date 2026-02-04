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
if (N > 0) {
    for (int k = 0; k < 1; k++) {
        int i;
        for (i = 0; i < N; i++) {
            Y[iy] *= beta;
            iy += incY;
        }
    }
}
}
