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
    for (i = 0; i < len; i++) {
        w_val0 = w[i];
        if (w_val0 > 0.0) {
            sum00 += v0[i] * w_val0;
            sum10 += v1[i] * w_val0;
        } else {
            sum20 += v2[i] * w_val0;
            sum30 += v3[i] * w_val0;
        }
    }
}
