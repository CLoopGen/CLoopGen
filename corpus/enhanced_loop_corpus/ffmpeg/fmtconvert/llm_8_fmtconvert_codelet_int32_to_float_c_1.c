#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  int32_t *src;
extern intptr_t len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            dst[i]     = (float)src[i];
            dst[i + 1] = (float)src[i + 1];
        } else {
            dst[i] = (float)src[i];
        }
    }
}
