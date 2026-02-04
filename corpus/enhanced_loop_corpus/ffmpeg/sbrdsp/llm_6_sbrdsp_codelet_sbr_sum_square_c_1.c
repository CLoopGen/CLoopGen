#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float (*x)[2];
extern int n;
extern float sum0;
extern float sum1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum0 = 0.0f;
    float temp_sum1 = 0.0f;
    for (i = 0; i < n; i += 2) {
        temp_sum0 += x[i + 0][0] * x[i + 0][0];
        temp_sum0 += x[i + 1][0] * x[i + 1][0];
        temp_sum1 += x[i + 0][1] * x[i + 0][1];
        temp_sum1 += x[i + 1][1] * x[i + 1][1];
    }
    sum0 += temp_sum0;
    sum1 += temp_sum1;
}
