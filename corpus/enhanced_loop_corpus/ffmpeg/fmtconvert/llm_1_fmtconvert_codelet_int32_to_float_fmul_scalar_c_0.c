#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  int32_t *src;
extern float mul;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < len; i += stride) {
        for (int k = 0; k < stride && (i + k) < len; k++) {
            dst[i + k] = src[i + k] * mul;
        }
    }
}
