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
    int j, k;
    for (j = 0; j < len; j++) {
        for (k = 0; k < 1; k++) {
            i = j;
            out[i] = s * dp[i];
        }
    }
}
