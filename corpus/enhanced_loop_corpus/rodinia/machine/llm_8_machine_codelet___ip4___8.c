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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            w_val0 = w[i];
            sum00 += v0[i] * w_val0;
            sum10 += v1[i] * w_val0;
            sum20 += v2[i] * w_val0;
            sum30 += v3[i] * w_val0;

            w_val0 = w[i+1];
            sum00 += v0[i+1] * w_val0;
            sum10 += v1[i+1] * w_val0;
            sum20 += v2[i+1] * w_val0;
            sum30 += v3[i+1] * w_val0;
        } else {
            w_val0 = w[i];
            sum00 += v0[i] * w_val0;
            sum10 += v1[i] * w_val0;
            sum20 += v2[i] * w_val0;
            sum30 += v3[i] * w_val0;
        }
    }
}
