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
for (j = 1; j <= nh; j += 2) {
    float sum1 = 0.0f, sum2 = 0.0f;
    float h1, h2;
    int j1 = j;
    int j2 = j + 1;

    h1 = hidden[j1];
    if (j2 <= nh) {
        h2 = hidden[j2];
    }

    for (k = 1; k <= no; k++) {
        sum1 += delta_o[k] * who[j1][k];
        if (j2 <= nh) {
            sum2 += delta_o[k] * who[j2][k];
        }
    }

    delta_h[j1] = h1 * (1.0f - h1) * sum1;
    errsum += (delta_h[j1] > 0.0f) ? delta_h[j1] : -delta_h[j1];

    if (j2 <= nh) {
        delta_h[j2] = h2 * (1.0f - h2) * sum2;
        errsum += (delta_h[j2] > 0.0f) ? delta_h[j2] : -delta_h[j2];
    }
}
}
