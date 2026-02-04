#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double s;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double acc = 0.0;
    for (i = 0; i < len; i++) {
        acc += s * dp2[i];
        dp1[i] += acc;
        acc = acc * 0.9; // Introduce WAW and loop-carried dependency
    }
    // Final write to memory with accumulated effect
    dp1[len-1] += acc;
}
