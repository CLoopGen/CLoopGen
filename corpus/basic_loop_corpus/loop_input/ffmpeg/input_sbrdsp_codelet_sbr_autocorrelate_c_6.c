#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

float x[40][2];
float real_sum2 = 0.0f;
float imag_sum2 = 0.0f;
float real_sum1 = 0.0f;
float imag_sum1 = 0.0f;
float real_sum0 = 0.0f;
int i = 0;

void init_vars() {
    for (int idx = 0; idx < 40; idx++) {
        x[idx][0] = (float)(idx % 7 + 1);
        x[idx][1] = (float)(idx % 5 + 1);
    }
}