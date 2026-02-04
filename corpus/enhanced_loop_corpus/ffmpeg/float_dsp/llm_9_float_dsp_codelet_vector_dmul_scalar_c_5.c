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
    int i;
    for (i = 0; i < len * 2; i += 2) {
        int j = i / 2;
        if (j < len) {
            double temp = src[j] * mul;
            dst[j] = temp * temp - 2.0 * temp + 1.0; // (mul*src[j] - 1)^2
        }
    }
}
