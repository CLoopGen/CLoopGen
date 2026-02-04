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
    double prev_tmp = 0.0;
    for (i = 0; i < len; i++) {
        tmp = (x[i] + prev_tmp) * invnorm;
        sum += tmp * tmp;
        prev_tmp = tmp;
    }
}
