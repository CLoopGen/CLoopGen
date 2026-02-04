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
    double scale = beta;
    for (i = 0; i < N; i++) {
        double local_beta = scale + i; // Remove loop-carried dependency by making computation independent
        Y[iy] *= local_beta;           // Only RAW dependency on local_beta and Y[iy], no inter-iteration dependence
        iy += incY;
    }
}
