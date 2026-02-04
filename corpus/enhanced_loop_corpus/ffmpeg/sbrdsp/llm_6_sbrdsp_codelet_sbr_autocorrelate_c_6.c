#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float x[40][2];
extern float real_sum2;
extern float imag_sum2;
extern float real_sum1;
extern float imag_sum1;
extern float real_sum0;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_real0 = 0.0f, temp_real1 = 0.0f, temp_imag1 = 0.0f;
    float temp_real2 = 0.0f, temp_imag2 = 0.0f;

    for (i = 1; i < 38; i++) {
        temp_real0 += x[i][0] * x[i][0] + x[i][1] * x[i][1];
        temp_real1 += x[i][0] * x[i + 1][0] + x[i][1] * x[i + 1][1];
        temp_imag1 += x[i][0] * x[i + 1][1] - x[i][1] * x[i + 1][0];
        temp_real2 += x[i][0] * x[i + 2][0] + x[i][1] * x[i + 2][1];
        temp_imag2 += x[i][0] * x[i + 2][1] - x[i][1] * x[i + 2][0];
    }

    real_sum0 += temp_real0;
    real_sum1 += temp_real1;
    imag_sum1 += temp_imag1;
    real_sum2 += temp_real2;
    imag_sum2 += temp_imag2;
}
