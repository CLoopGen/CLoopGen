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
    float temp_c = c;
    float temp_s = s;
    for (i = 0; i < N; i++) {
        const float x = X[ix];
        const float y = Y[iy];
        // Introduce temporary variables to remove direct WAW and WAR hazards
        // and break potential loop-carried dependencies on memory writes
        float new_x = temp_c * x + temp_s * y;
        float new_y = -temp_s * x + temp_c * y;
        X[ix] = new_x;
        Y[iy] = new_y;
        ix += incX;
        iy += incY;
    }
}
