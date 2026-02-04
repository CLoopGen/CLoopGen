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
    for (i = 1; i < len; i++)
        out[i] = dp1[i-1] + dp2[i];
    if (len > 0)
        out[0] = dp1[0] + dp2[0];
}
