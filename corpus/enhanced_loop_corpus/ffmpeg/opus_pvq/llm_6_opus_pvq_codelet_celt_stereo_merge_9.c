#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern float mid;
extern int N;
extern int i;
extern float gain[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i++) {
    float temp_x = X[i];
    float temp_y = Y[i];
    float computed_mid_x = mid * temp_x;
    X[i] = gain[0] * (computed_mid_x - temp_y);
    Y[i] = gain[1] * (computed_mid_x + temp_y);
}
}
