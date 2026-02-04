#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_x, temp_y;
    for (i = 0; i < N; i++) {
        temp_x = X[i];
        temp_y = Y[i];
        X[i] = (temp_x + temp_y) * 0.70710678118654757;
        Y[i] = (temp_y - temp_x) * 0.70710678118654757;
    }
}
