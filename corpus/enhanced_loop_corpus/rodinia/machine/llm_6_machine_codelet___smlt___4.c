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
    double temp_s = s;
    for (i = 0; i < len; i++) {
        out[i] = temp_s * dp[i];
    }
}
