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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            dst[i]     = src[i] * (1.F / (2.F * 2147483647));
            dst[i + 1] = src[i + 1] * (1.F / (2.F * 2147483647));
        } else {
            dst[i] = src[i] * (1.F / (2.F * 2147483647));
        }
    }
}
