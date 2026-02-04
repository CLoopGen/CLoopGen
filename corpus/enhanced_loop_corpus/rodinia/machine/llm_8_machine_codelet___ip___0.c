#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern int len;
extern int i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0.0;
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            sum += dp1[i] * dp2[i] + dp1[i+1] * dp2[i+1];
        } else {
            sum += dp1[i] * dp2[i];
        }
    }
}
