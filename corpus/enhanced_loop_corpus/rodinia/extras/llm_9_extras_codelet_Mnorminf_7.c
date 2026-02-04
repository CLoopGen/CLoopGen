#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern int i;
extern double tmp;
extern double max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double tmp1, tmp2;
for (i = 0; i < len; i++) {
    tmp1 = x[i] * x[i];
    tmp2 = max_val * max_val;
    if (tmp2 < tmp1)
        max_val = ((x[i]) >= 0 ? (x[i]) : -(x[i]));
}
}
