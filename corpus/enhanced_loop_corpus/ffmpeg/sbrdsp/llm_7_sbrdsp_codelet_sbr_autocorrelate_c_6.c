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
    for (i = 1; i < 38; i += 2) {
        real_sum0 += x[i][0] * x[i][0] + x[i][1] * x[i][1];

        if (i + 1 < 38) {
            real_sum0 += x[i + 1][0] * x[i + 1][0] + x[i + 1][1] * x[i + 1][1];
        }

        if (i + 2 < 38) {
            real_sum1 += x[i][0] * x[i + 1][0] + x[i][1] * x[i + 1][1];
            imag_sum1 += x[i][0] * x[i + 1][1] - x[i][1] * x[i + 1][0];
        }

        if (i + 3 < 38) {
            real_sum1 += x[i + 1][0] * x[i + 2][0] + x[i + 1][1] * x[i + 2][1];
            imag_sum1 += x[i + 1][0] * x[i + 2][1] - x[i + 1][1] * x[i + 2][0];
        }

        if (i + 4 < 38) {
            real_sum2 += x[i][0] * x[i + 2][0] + x[i][1] * x[i + 2][1];
            imag_sum2 += x[i][0] * x[i + 2][1] - x[i][1] * x[i + 2][0];
        }

        if (i + 5 < 38) {
            real_sum2 += x[i + 1][0] * x[i + 3][0] + x[i + 1][1] * x[i + 3][1];
            imag_sum2 += x[i + 1][0] * x[i + 3][1] - x[i + 1][1] * x[i + 3][0];
        }
    }
}
