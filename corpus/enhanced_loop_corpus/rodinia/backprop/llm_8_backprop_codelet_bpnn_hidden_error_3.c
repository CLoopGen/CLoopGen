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
int j_start = 1;
int j_end = nh;
int k_end = no;

for (j = j_start; j <= j_end; j++) {
    h = hidden[j];
    sum = 0.;
    for (k = 1; k <= k_end; k += 2) {
        if (k + 1 <= k_end) {
            sum += delta_o[k] * who[j][k] + delta_o[k+1] * who[j][k+1];
        } else {
            sum += delta_o[k] * who[j][k];
        }
    }
    delta_h[j] = h * (1.0f - h) * sum;
    float abs_delta = delta_h[j];
    errsum += (abs_delta > 0.0f) ? abs_delta : -abs_delta;
}
}
