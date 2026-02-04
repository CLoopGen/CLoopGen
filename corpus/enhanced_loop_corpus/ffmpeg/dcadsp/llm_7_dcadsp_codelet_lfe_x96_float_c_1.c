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
    float running_prev = prev;
    for (i = 0; i < len; i++) {
        float s = src[i];
        float next_a = 0.25F * s + 0.75F * running_prev;
        float next_b = 0.75F * s + 0.25F * running_prev;
        running_prev = s;
        *dst++ = next_a;
        *dst++ = next_b;
    }
    prev = running_prev;
}
