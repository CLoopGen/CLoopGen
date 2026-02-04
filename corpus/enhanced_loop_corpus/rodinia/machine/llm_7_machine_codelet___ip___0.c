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
    double local_sum = 0.0;
    for (i = 0; i < len; i += 2) {
        double prod1 = dp1[i] * dp2[i];
        double prod2 = (i + 1 < len) ? dp1[i + 1] * dp2[i + 1] : 0.0;
        local_sum += prod1 + prod2;
    }
    sum = local_sum;
}
