#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern double *y;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < len; i += 2) {
        if (i < len) y[i] = x[i];
        if (i + 1 < len) y[i + 1] = x[i + 1];
    }
}
