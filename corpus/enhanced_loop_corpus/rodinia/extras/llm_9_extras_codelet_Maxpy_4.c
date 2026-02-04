#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double alpha;
extern double *x;
extern double *y;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double alpha_sq = alpha * alpha;
    for (i = 0; i < len; i++) {
        y[i] += alpha * x[i] + alpha_sq * x[i] * 0.5;
    }
}
