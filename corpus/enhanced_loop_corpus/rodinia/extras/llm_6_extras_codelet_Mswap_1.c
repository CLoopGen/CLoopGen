#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern double *y;
extern int i;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double tmp_local;
    for (i = 0; i < len; i++) {
        tmp_local = x[i];
        x[i] = y[i];
        y[i] = tmp_local;
    }
}
