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
    int stride = 4;
    for (i = 0; i < len; i += stride) {
        for (int j = 0; j < stride; j++) {
            if (i + j < len)
                dst[i + j] += src[i + j] * mul;
        }
    }
}
