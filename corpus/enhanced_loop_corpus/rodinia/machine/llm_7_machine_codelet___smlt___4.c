#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp;
extern double s;
extern double *out;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double acc = 0.0;
    for (i = 0; i < len; i++) {
        acc += s * dp[i];
        out[i] = acc;
    }
}
