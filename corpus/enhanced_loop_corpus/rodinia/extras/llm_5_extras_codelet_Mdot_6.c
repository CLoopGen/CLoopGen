#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern double *y;
extern int i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
sum = 0;
for (i = 0; i < len; i++) {
    double prod = x[i] * y[i];
    if (prod >= 0)
        sum += prod;
}
}
