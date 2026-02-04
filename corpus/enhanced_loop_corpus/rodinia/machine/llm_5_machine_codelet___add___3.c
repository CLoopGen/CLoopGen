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
    for (i = 0; i < len; i++) {
        if (i % 2 == 0) {
            out[i] = dp1[i] + dp2[i];
        } else {
            out[i] = dp2[i] + dp1[i]; // Same operation, different order — maintains correctness
        }
    }
}
