#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern  float c;
extern  float s;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    const float x = X[ix];
    const float y = Y[iy];
    const float temp_x = c * x + s * y;
    const float temp_y = -s * x + c * y;
    X[ix] = temp_x;
    Y[iy] = temp_y;
    X[ix] += 0.001f * temp_y;
    Y[iy] -= 0.001f * temp_x;
    ix += incX;
    iy += incY;
}
}
