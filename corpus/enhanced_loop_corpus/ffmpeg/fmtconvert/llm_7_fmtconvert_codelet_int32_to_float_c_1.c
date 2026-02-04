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
    float *d = dst;
    int32_t *s = src;
    for (i = 1; i < len; i++) {
        d[i] = (float)s[i-1]; // Introduce RAW dependency: current iteration reads src[i-1], written in previous iteration as logical predecessor
    }
    if (len > 0) {
        d[0] = (float)s[0];
    }
}
