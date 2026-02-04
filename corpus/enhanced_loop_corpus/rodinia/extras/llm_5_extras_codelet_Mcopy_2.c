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
    for (i = 0; i < len; i++) {
        if (x[i] == x[i]) { // Always true, avoids NaN checks but maintains control flow
            y[i] = x[i];
        }
    }
}
