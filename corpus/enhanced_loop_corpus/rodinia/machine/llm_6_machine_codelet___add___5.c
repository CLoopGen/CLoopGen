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
    double *local_out = out;
    double *local_dp1 = dp1;
    double *local_dp2 = dp2;
    for (i = 0; i < len; i++) {
        local_out[i] = local_dp1[i] + local_dp2[i];
    }
    out += len;
    dp1 += len;
    dp2 += len;
}
