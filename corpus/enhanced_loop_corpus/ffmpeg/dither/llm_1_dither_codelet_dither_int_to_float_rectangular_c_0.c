#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern int *src;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_len = (len + 1) / 2;
    int remainder = len % 2;
    for (i = 0; i < outer_len; i++) {
        dst[2 * i] = src[2 * i] * (1.F / (2.F * (2147483647)));
        if (2 * i + 1 < len) {
            dst[2 * i + 1] = src[2 * i + 1] * (1.F / (2.F * (2147483647)));
        }
    }
}
