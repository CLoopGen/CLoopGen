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
for (i = 0; i < len; i += 2) {
    if (i + 1 < len) {
        tmp = x[i];
        x[i] = y[i];
        y[i] = tmp;
        tmp = x[i+1];
        x[i+1] = y[i+1];
        y[i+1] = tmp;
    } else {
        tmp = x[i];
        x[i] = y[i];
        y[i] = tmp;
    }
}
}
