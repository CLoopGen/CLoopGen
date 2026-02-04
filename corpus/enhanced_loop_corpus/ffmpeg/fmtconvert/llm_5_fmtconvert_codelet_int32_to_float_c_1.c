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
    for (i = 0; i < len; i++) {
        float value = (float)src[i];
        if (value > 0.0f) {
            dst[i] = value * 1.1f;
        } else {
            dst[i] = value * 0.9f;
        }
    }
}
