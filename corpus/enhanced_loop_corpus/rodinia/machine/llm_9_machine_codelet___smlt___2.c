#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp;
extern double *out;
extern double s;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double local_s = s + 1.0;
    double offset = s * 0.5;
    for (i = 0; i < len; i++) {
        out[i] = local_s * dp[i] + offset;
    }
}
