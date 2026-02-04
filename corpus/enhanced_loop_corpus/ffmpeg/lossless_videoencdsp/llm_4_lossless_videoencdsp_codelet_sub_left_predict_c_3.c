#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern ptrdiff_t width;
extern int height;
extern int i;
extern int j;
extern uint8_t prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < height; j++) {
    for (i = 0; i < width; i++) {
        uint8_t current = src[i];
        *dst++ = current - prev;
        prev = current;
    }
    src += stride;
}
}
