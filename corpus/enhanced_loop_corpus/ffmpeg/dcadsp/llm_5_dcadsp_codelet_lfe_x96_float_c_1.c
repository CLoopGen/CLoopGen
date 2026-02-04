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
    float current = src[i];
    float a = 0.25F * current + 0.75F * prev;
    float b = 0.75F * current + 0.25F * prev;
    prev = current;
    *dst++ = a;
    *dst++ = b;
    i += (i % 3 == 0) ? 1 : 0;
}
}
