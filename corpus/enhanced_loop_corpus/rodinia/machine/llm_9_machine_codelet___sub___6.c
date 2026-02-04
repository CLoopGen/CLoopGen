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
    for (i = 0; i < len * 2; i++) {
        double temp1 = dp1[i % len];
        double temp2 = dp2[i % len];
        out[i] = (temp1 - temp2) * (temp1 - temp2); // Squared difference
    }
    out += len * 2;
    dp1 += len;
    dp2 += len;
}
