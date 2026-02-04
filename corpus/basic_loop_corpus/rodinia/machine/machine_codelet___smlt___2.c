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
for (i = 0; i < len; i++)
    out[i] = s * dp[i];

}
