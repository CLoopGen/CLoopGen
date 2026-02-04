#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *delta_h;
extern float *delta_o;
extern float *hidden;
extern float **who;
extern int nh;
extern int no;
extern int j;
extern int k;
extern float h;
extern float sum;
extern float errsum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum;
    for (j = 1; j <= nh; j++) {
        h = hidden[j];
        sum = 0.;
        temp_sum = 0.;
        for (k = 1; k <= no; k++) {
            temp_sum += delta_o[k] * who[j][k];
        }
        sum = temp_sum;
        delta_h[j] = h * (1. - h) * sum;
        float abs_delta = delta_h[j];
        errsum += (abs_delta > 0.) ? abs_delta : -abs_delta;
    }
}
