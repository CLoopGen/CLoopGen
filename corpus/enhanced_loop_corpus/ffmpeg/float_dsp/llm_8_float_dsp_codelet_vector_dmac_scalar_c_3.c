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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            dst[i] += src[i] * mul;
            dst[i+1] += src[i+1] * mul;
        } else {
            dst[i] += src[i] * mul;
        }
    }
}
