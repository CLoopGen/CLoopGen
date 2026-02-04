#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t w;
extern int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    acc += src[i] + src[i] * 2;
    dst[i] = acc >> 1;
    acc += src[i];
    dst[i] = acc;
}
}
