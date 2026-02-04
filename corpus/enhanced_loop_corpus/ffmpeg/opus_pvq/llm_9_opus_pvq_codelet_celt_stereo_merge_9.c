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
    float mid_x = mid * temp_x;
    float diff = mid_x - temp_y;
    float sum = mid_x + temp_y;
    // Additional computational steps to increase arithmetic intensity
    diff = (diff + diff * 0.1f) * gain[0];
    sum = (sum + sum * 0.1f) * gain[1];
    X[i] = diff;
    Y[i] = sum;
}
}
