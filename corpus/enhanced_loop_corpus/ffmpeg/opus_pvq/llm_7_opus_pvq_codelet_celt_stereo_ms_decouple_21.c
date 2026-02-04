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
    float prev_x = 0.0f;
    for (i = 0; i < N; i++) {
        const float current_x = X[i];
        X[i] = (X[i] + Y[i]) * 0.70710678118654757;
        Y[i] = (Y[i] - prev_x) * 0.70710678118654757;
        prev_x = current_x;
    }
}
