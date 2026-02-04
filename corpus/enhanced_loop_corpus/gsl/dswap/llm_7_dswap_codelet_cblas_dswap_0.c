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
    double prev_X_val = 0.0;
    double current_X_val;
    int j = 0;
    int local_ix = ix;
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        current_X_val = X[local_ix];
        X[local_ix] = (i == 0) ? Y[local_iy] : Y[local_iy] + prev_X_val;
        Y[local_iy] = current_X_val;
        prev_X_val = current_X_val;
        local_ix += incX;
        local_iy += incY;
        j++;
    }
    ix = local_ix;
    iy = local_iy;
}
