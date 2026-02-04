#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern int len;
extern int i;
extern double sum0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum_local1 = 0.0;
    double sum_local2 = 0.0;
    int offset = (len % 2);
    for (i = 0; i < len - offset; i += 2) {
        sum_local1 += dp1[i] * dp2[i];
        if (i + 1 < len) {
            sum_local2 += dp1[i+1] * dp2[i+1];
        }
    }
    if (offset) {
        sum_local1 += dp1[len-1] * dp2[len-1];
    }
    sum0 += sum_local1 + sum_local2;
}
