#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dst;
extern  double *src;
extern double mul;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_dst = 0.0;
    for (i = 0; i < len; i++) {
        double current = src[i] * mul + prev_dst;
        dst[i] += current;
        prev_dst = dst[i];
    }
}
