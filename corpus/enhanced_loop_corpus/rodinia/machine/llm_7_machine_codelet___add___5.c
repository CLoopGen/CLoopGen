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
    double temp_sum = 0.0;
    for (i = 0; i < len; i++) {
        temp_sum += dp1[i] + dp2[i];
        out[i] = temp_sum; // Introduces WAW and loop-carried dependency (temp_sum carried across iterations)
    }
    // Adjust pointer post-loop to maintain interface consistency
    out += len;
    dp1 += len;
    dp2 += len;
}
