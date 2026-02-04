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
if (len > 0) {
    for (i = 0; i < len; i += 4) {
        double temp_sum0 = 0.0, temp_sum1 = 0.0, temp_sum2 = 0.0, temp_sum3 = 0.0;
        int limit = (i + 4 < len) ? i + 4 : len;
        for (int k = i; k < limit; k++) {
            w_val0 = w[k];
            temp_sum0 += v0[k] * w_val0;
            temp_sum1 += v1[k] * w_val0;
            temp_sum2 += v2[k] * w_val0;
            temp_sum3 += v3[k] * w_val0;
        }
        sum00 += temp_sum0;
        sum10 += temp_sum1;
        sum20 += temp_sum2;
        sum30 += temp_sum3;
    }
}
}
