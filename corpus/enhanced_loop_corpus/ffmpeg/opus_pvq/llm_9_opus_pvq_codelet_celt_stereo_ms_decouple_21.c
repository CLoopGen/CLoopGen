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
for (i = 0; i < N; i++) {
    const float xi = X[i];
    const float yi = Y[i];
    const float temp_sum = (xi + yi) * 0.70710678118654757;
    const float temp_diff = (yi - xi) * 0.70710678118654757;
    X[i] = temp_sum;
    Y[i] = temp_diff;
}
}
