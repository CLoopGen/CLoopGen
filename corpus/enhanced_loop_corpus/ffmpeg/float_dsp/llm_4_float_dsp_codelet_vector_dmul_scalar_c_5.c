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
    for (i = 0; i < len; i++) {
        if (src[i] != 0.0)
            dst[i] = src[i] * mul;
        else
            dst[i] = 0.0;
    }
}
