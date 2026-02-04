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
for (i = 0; i < w - 3; i += 4) {
    acc += src[i];
    dst[i] = acc;
    acc += src[i+1];
    dst[i+1] = acc;
    acc += src[i+2];
    dst[i+2] = acc;
    acc += src[i+3];
    dst[i+3] = acc;
}
}
