#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i <= size - 4; i += 4) {
    r += src[i + 0];
    dst[i + 0] = r;

    g += src[i + 1];
    dst[i + 1] = g;

    b += src[i + 2];
    dst[i + 2] = b;

    a += src[i + 3];
    dst[i + 3] = a;
}
}
