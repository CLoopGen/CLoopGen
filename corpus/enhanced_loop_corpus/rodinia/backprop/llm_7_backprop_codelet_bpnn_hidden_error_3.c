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
    float *dh = delta_h;
    float *do_arr = delta_o;
    float **weights = who;
    float local_errsum = 0.0f;
    for (j = 1; j <= nh; j++) {
        h = hidden[j];
        sum = 0.;
        for (k = 1; k <= no; k++) {
            sum += do_arr[k] * weights[j][k];
        }
        float dh_val = h * (1. - h) * sum;
        dh[j] = dh_val;
        local_errsum += (dh_val > 0.) ? dh_val : -dh_val;
    }
    errsum += local_errsum;
}
