#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float *X;
extern  int incX;
extern  float *Y;
extern  int incY;
extern float r;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        float temp_x = X[ix];
        float temp_y = Y[iy];
        if (temp_x > 0.0f) {
            r += temp_x * temp_y;
        }
        ix += incX;
        iy += incY;
    }
}
