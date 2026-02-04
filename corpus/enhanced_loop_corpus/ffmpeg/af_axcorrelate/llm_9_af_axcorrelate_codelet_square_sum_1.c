#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern int size;
extern float square_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum1 = 0.0f;
    float temp_sum2 = 0.0f;
    float temp_sum3 = 0.0f;
    float temp_sum4 = 0.0f;
    int i = 0;
    for (; i < size - 3; i += 4) {
        temp_sum1 += x[i] * y[i];
        temp_sum2 += x[i+1] * y[i+1];
        temp_sum3 += x[i+2] * y[i+2];
        temp_sum4 += x[i+3] * y[i+3];
    }
    for (; i < size; i++) {
        square_sum += x[i] * y[i];
    }
    square_sum += temp_sum1 + temp_sum2 + temp_sum3 + temp_sum4;
}
