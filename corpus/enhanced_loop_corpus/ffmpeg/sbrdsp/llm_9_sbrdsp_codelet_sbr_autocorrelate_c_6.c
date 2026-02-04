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
for (i = 1; i < 38; i++) {
    float temp_real1 = x[i][0] * x[i + 1][0] + x[i][1] * x[i + 1][1];
    float temp_imag1 = x[i][0] * x[i + 1][1] - x[i][1] * x[i + 1][0];
    float temp_real2 = x[i][0] * x[i + 2][0] + x[i][1] * x[i + 2][1];
    float temp_imag2 = x[i][0] * x[i + 2][1] - x[i][1] * x[i + 2][0];
    float temp_norm = x[i][0] * x[i][0] + x[i][1] * x[i][1];

    // Accumulate with additional computational steps to increase intensity
    real_sum0 = real_sum0 + temp_norm + (temp_real1 * 0.1f);
    real_sum1 = real_sum1 + temp_real1 + (temp_norm * 0.05f);
    imag_sum1 = imag_sum1 + temp_imag1;
    real_sum2 = real_sum2 + temp_real2 + (temp_imag2 * 0.02f);
    imag_sum2 = imag_sum2 + temp_imag2;

    // Additional dummy computation to increase arithmetic intensity
    float extra = temp_real1 * temp_imag1 - temp_real2 * temp_norm;
    real_sum0 += (extra * extra) * 0.001f;
}
}
