#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        double a = dp1[i] * 2.0;
        double b = dp2[i] * 3.0;
        double c = a + b;
        double d = c * c; // Additional arithmetic intensity
        out[i] = d - a;   // More operations per iteration
    }
}
