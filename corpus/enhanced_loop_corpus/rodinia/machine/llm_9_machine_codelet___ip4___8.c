#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *v0;
extern double *v1;
extern double *v2;
extern double *v3;
extern double *w;
extern int len;
extern int i;
extern double sum00;
extern double sum10;
extern double sum20;
extern double sum30;
extern double w_val0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double sum00_local = 0.0, sum10_local = 0.0, sum20_local = 0.0, sum30_local = 0.0;
    for (i = 0; i < len; i++) {
        double temp = w[i];
        sum00_local += v0[i] * temp;
        sum10_local += v1[i] * temp;
        sum20_local += v2[i] * temp;
        sum30_local += v3[i] * temp;
    }
    sum00 += sum00_local;
    sum10 += sum10_local;
    sum20 += sum20_local;
    sum30 += sum30_local;
}
