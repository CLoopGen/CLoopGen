#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int n;
extern int i;
extern int j;
extern float h11;
extern float h21;
extern float h12;
extern float h22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_x, temp_y;
    for (n = 0; n < N; n++) {
        const float w = X[i];
        const float z = Y[j];
        temp_x = h11 * w + h12 * z;
        temp_y = h21 * w + h22 * z;
        X[i] = temp_x;
        Y[j] = temp_y;
        i += incX;
        j += incY;
    }
}
