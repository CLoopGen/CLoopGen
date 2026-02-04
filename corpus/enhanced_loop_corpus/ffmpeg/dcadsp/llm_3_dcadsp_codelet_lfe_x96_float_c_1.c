#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src;
extern ptrdiff_t len;
extern float prev;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i += 2) {
    float s0 = src[i];
    float s1 = (i + 1 < len) ? src[i + 1] : s0;
    float a0 = 0.25F * s0 + 0.75F * prev;
    float b0 = 0.75F * s0 + 0.25F * prev;
    prev = s0;
    *dst++ = a0;
    *dst++ = b0;

    if (i + 1 < len) {
        float a1 = 0.25F * s1 + 0.75F * prev;
        float b1 = 0.75F * s1 + 0.25F * prev;
        prev = s1;
        *dst++ = a1;
        *dst++ = b1;
    }
}
}
