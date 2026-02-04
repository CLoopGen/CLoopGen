#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern int len;
extern int i;
extern double sum0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double sum1 = 0.0;
    for (i = 0; i < len; i++) {
        double a = dp1[i];
        double b = dp2[i];
        sum0 += a * a * b;  // Increased arithmetic intensity: a² * b instead of a * b
    }
}
