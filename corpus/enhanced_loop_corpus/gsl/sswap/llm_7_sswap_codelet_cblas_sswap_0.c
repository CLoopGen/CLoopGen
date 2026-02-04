#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_X_val = 0.0f;
    float current_X_val;
    for (i = 0; i < N; i++) {
        current_X_val = X[ix];
        X[ix] = Y[iy] + prev_X_val;
        Y[iy] = current_X_val;
        prev_X_val = current_X_val;
        ix += incX;
        iy += incY;
    }
}
