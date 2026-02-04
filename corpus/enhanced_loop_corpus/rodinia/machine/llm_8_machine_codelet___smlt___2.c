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
    double temp_s = s * 2.0;
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            out[i] = temp_s * dp[i];
            out[i+1] = temp_s * dp[i+1];
        } else {
            out[i] = temp_s * dp[i];
        }
    }
}
