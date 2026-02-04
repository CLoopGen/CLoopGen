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
        float a1, b1, a2, b2;
        a1 = 0.25F * src[i] + 0.75F * prev;
        b1 = 0.75F * src[i] + 0.25F * prev;
        *dst++ = a1;
        *dst++ = b1;
        if (i + 1 < len) {
            prev = src[i];
            a2 = 0.25F * src[i+1] + 0.75F * prev;
            b2 = 0.75F * src[i+1] + 0.25F * prev;
            *dst++ = a2;
            *dst++ = b2;
        }
        prev = src[i];
    }
}
