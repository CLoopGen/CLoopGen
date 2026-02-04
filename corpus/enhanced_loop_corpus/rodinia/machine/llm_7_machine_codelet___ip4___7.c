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
    for (i = 0; i < len2; i++) {
        double w0 = w[2 * i];
        double w1 = w[2 * i + 1];
        sum00 += v0[2 * i] * w0;
        sum10 += v1[2 * i] * w0;
        sum20 += v2[2 * i] * w0;
        sum30 += v3[2 * i] * w0;
        sum01 += v0[2 * i + 1] * w1;
        sum11 += v1[2 * i + 1] * w1;
        sum21 += v2[2 * i + 1] * w1;
        sum31 += v3[2 * i + 1] * w1;
    }
}
