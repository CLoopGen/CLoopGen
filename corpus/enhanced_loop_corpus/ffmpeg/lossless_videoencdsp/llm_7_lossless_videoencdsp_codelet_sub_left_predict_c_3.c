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
    uint8_t local_prev = prev;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            uint8_t diff = src[i] - local_prev;
            local_prev = src[i];
            *dst++ = diff;
        }
        src += stride;
    }
    prev = local_prev;
}
