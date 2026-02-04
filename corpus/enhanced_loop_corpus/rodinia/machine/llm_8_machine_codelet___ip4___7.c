#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *v0;
extern double *v1;
extern double *v2;
extern double *v3;
extern double *w;
extern int i;
extern int len2;
extern double sum00;
extern double sum10;
extern double sum20;
extern double sum30;
extern double w_val0;
extern double sum01;
extern double sum11;
extern double sum21;
extern double sum31;
extern double w_val1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop 2x and increasing arithmetic operations per iteration
    // Trip count is reduced by half, but each iteration processes two original iterations
    int i;
    for (i = 0; i < len2 - 1; i += 2) {
        double w_val0_0 = w[2 * i];
        double w_val1_0 = w[2 * i + 1];
        double w_val0_1 = w[2 * (i + 1)];
        double w_val1_1 = w[2 * (i + 1) + 1];

        sum00 += v0[2 * i] * w_val0_0 + v0[2 * (i + 1)] * w_val0_1;
        sum01 += v0[2 * i + 1] * w_val1_0 + v0[2 * (i + 1) + 1] * w_val1_1;
        sum10 += v1[2 * i] * w_val0_0 + v1[2 * (i + 1)] * w_val0_1;
        sum11 += v1[2 * i + 1] * w_val1_0 + v1[2 * (i + 1) + 1] * w_val1_1;
        sum20 += v2[2 * i] * w_val0_0 + v2[2 * (i + 1)] * w_val0_1;
        sum21 += v2[2 * i + 1] * w_val1_0 + v2[2 * (i + 1) + 1] * w_val1_1;
        sum30 += v3[2 * i] * w_val0_0 + v3[2 * (i + 1)] * w_val0_1;
        sum31 += v3[2 * i + 1] * w_val1_0 + v3[2 * (i + 1) + 1] * w_val1_1;
    }
    // Handle remaining element if len2 is odd
    if (i < len2) {
        w_val0 = w[2 * i];
        w_val1 = w[2 * i + 1];
        sum00 += v0[2 * i] * w_val0;
        sum01 += v0[2 * i + 1] * w_val1;
        sum10 += v1[2 * i] * w_val0;
        sum11 += v1[2 * i + 1] * w_val1;
        sum20 += v2[2 * i] * w_val0;
        sum21 += v2[2 * i + 1] * w_val1;
        sum30 += v3[2 * i] * w_val0;
        sum31 += v3[2 * i + 1] * w_val1;
    }
}
