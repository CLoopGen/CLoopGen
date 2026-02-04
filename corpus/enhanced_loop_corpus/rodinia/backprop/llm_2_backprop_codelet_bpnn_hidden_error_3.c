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
for (j = nh; j >= 1; j--) {
    h = hidden[j];
    sum = 0.;
    for (k = no; k >= 1; k--) {
        sum += delta_o[k] * who[j][k];
    }
    delta_h[j] = h * (1. - h) * sum;
    errsum += (((delta_h[j]) > 0.) ? (delta_h[j]) : (-(delta_h[j])));
}
}
