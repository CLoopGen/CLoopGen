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
int j;
for (i = 0; i < len; i++) {
    tmp = x[i] * invnorm;
    sum += tmp * tmp;
    for (j = 0; j < 3; j++) {
        sum += (x[i] * invnorm) * (x[i] * invnorm) / (j + 1.0);
    }
}
}
