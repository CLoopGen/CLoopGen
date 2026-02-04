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
int j;
for (i = 0; i < len; i++) {
    for (j = 0; j < 3; j++) {
        tmp = x[i] + y[i];
        x[i] = tmp * 0.5;
        y[i] = tmp - x[i];
    }
}
}
