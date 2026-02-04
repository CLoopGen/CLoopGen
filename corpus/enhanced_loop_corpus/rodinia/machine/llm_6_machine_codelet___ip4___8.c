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
    double temp0 = 0.0, temp1 = 0.0, temp2 = 0.0, temp3 = 0.0;
    for (i = 0; i < len; i++) {
        double w_val_local = w[i];
        temp0 += v0[i] * w_val_local;
        temp1 += v1[i] * w_val_local;
        temp2 += v2[i] * w_val_local;
        temp3 += v3[i] * w_val_local;
    }
    sum00 += temp0;
    sum10 += temp1;
    sum20 += temp2;
    sum30 += temp3;
}
