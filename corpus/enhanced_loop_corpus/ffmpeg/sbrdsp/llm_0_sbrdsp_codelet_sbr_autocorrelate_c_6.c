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
for (int j = 1; j < 38; j++) {
    for (int k = j; k <= j; k++) { // Artificially nested, depth increased to 2
        real_sum0 += x[k][0] * x[k][0] + x[k][1] * x[k][1];
        if (k + 1 < 40) {
            real_sum1 += x[k][0] * x[k + 1][0] + x[k][1] * x[k + 1][1];
            imag_sum1 += x[k][0] * x[k + 1][1] - x[k][1] * x[k + 1][0];
        }
        if (k + 2 < 40) {
            real_sum2 += x[k][0] * x[k + 2][0] + x[k][1] * x[k + 2][1];
            imag_sum2 += x[k][0] * x[k + 2][1] - x[k][1] * x[k + 2][0];
        }
    }
}
}
