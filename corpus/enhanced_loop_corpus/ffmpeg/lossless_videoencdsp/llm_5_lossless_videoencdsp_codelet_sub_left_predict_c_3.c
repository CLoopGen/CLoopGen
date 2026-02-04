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
    if (width > 0) {
        *dst++ = src[0] - prev;
        prev = src[0];
        for (i = 1; i < width; i++) {
            uint8_t diff = src[i] - src[i-1];
            *dst++ = diff;
            prev = src[i];
        }
    }
    src += stride;
}
}
