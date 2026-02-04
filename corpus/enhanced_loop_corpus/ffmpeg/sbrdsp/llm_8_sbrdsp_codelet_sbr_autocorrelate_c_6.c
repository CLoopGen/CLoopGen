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
for (i = 2; i < 37; i += 2) {
    float xi0 = x[i][0], xi1 = x[i][1];
    float xi1_0 = x[i+1][0], xi1_1 = x[i+1][1];
    float xi2_0 = x[i+2][0], xi2_1 = x[i+2][1];

    real_sum0 += xi0 * xi0 + xi1 * xi1;
    real_sum1 += xi0 * xi1_0 + xi1 * xi1_1;
    imag_sum1 += xi0 * xi1_1 - xi1 * xi1_0;
    real_sum2 += xi0 * xi2_0 + xi1 * xi2_1;
    imag_sum2 += xi0 * xi2_1 - xi1 * xi2_0;

    // Unroll and process i+1 iteration manually if within bounds
    if (i + 1 < 37) {
        float xj0 = x[i+1][0], xj1 = x[i+1][1];
        float xj1_0 = x[i+2][0], xj1_1 = x[i+2][1];
        float xj2_0 = x[i+3][0], xj2_1 = x[i+3][1];

        real_sum0 += xj0 * xj0 + xj1 * xj1;
        real_sum1 += xj0 * xj1_0 + xj1 * xj1_1;
        imag_sum1 += xj0 * xj1_1 - xj1 * xj1_0;
        real_sum2 += xj0 * xj2_0 + xj1 * xj2_1;
        imag_sum2 += xj0 * xj2_1 - xj1 * xj2_0;
    }
}
}
