#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern int i;
extern double invnorm;
extern double sum;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (i = 0; i < len; i++) {
        double tmp_local = x[i] * invnorm;
        temp_sum += tmp_local * tmp_local;
    }
    sum += temp_sum;
}
