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
for (i = 0; i < len; i++) {
    float a = 0.25F * src[i] + 0.75F * prev;
    float b = 0.75F * src[i] + 0.25F * prev;
    prev = src[i];
    *dst++ = a;
    if (b > 0.0F) {
        *dst++ = b;
    }
}
}
