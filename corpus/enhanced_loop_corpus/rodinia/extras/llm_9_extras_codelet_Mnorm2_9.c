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
for (i = 0; i < len; i += 2) {
    if (i + 1 < len) {
        double tmp1 = x[i] * invnorm;
        double tmp2 = x[i+1] * invnorm;
        sum += tmp1 * tmp1 + tmp2 * tmp2;
    } else {
        tmp = x[i] * invnorm;
        sum += tmp * tmp;
    }
}
}
