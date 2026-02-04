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
    // Variant 2: Reverse sequential access
    // Traverse the arrays from last element to first
    for (i = len - 1; i >= 0; i--)
        out[i] = s * dp[i];
}
