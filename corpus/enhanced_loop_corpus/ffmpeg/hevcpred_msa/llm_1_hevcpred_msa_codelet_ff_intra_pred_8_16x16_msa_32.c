#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern ptrdiff_t stride;
extern uint8_t *src;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    left[i*4 + 0] = src[(-1) + stride * (i*4 + 0)];
    left[i*4 + 1] = src[(-1) + stride * (i*4 + 1)];
    left[i*4 + 2] = src[(-1) + stride * (i*4 + 2)];
    left[i*4 + 3] = src[(-1) + stride * (i*4 + 3)];
}
}
