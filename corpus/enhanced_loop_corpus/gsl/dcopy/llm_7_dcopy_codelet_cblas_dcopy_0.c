#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_ix = ix;
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        Y[local_iy] = X[local_ix];  // Eliminate loop-carried dependency on global ix/iy
        local_ix += incX;
        local_iy += incY;
    }
    ix = local_ix;  // Update globals only after loop
    iy = local_iy;
}
