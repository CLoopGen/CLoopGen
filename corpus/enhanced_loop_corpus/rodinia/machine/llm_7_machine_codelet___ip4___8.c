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
    sum00 = 0.0;
    sum10 = 0.0;
    sum20 = 0.0;
    sum30 = 0.0;
    double w_val_prev = w[0];
    for (i = 0; i < len; i++) {
        double w_val_curr = w[i];
        w_val0 = (i == 0) ? w_val_curr : w_val_prev; // Introduce WAR: w_val0 written after read in prev iteration
        sum00 += v0[i] * w_val0;
        sum10 += v1[i] * w_val0;
        sum20 += v2[i] * w_val0;
        sum30 += v3[i] * w_val0;
        w_val_prev = w_val_curr; // Create loop-carried dependency (RAW): current depends on prior write
    }
}
