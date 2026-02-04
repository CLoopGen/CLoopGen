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
// Use reverse traversal for memory access — modifying access pattern to consecutive but in reverse
for (i = 37; i >= 1; i--) {
    real_sum0 += x[i][0] * x[i][0] + x[i][1] * x[i][1];
    real_sum1 += x[i][0] * x[i + 1][0] + x[i][1] * x[i + 1][1];
    imag_sum1 += x[i][0] * x[i + 1][1] - x[i][1] * x[i + 1][0];
    real_sum2 += x[i][0] * x[i + 2][0] + x[i][1] * x[i + 2][1];
    imag_sum2 += x[i][0] * x[i + 2][1] - x[i][1] * x[i + 2][0];
}
}
