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
    float temp_prev = prev;
    for (i = 0; i < len; i++) {
        float current = src[i];
        float a = 0.25F * current + 0.75F * temp_prev;
        float b = 0.75F * current + 0.25F * temp_prev;
        temp_prev = current;
        dst[2*i] = a;
        dst[2*i + 1] = b;
    }
    prev = src[len - 1];
}
