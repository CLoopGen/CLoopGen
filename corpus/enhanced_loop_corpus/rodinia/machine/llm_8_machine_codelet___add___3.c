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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            out[i]     = dp1[i] + dp2[i];
            out[i + 1] = dp1[i + 1] + dp2[i + 1];
        } else {
            out[i] = dp1[i] + dp2[i];
        }
    }
}
