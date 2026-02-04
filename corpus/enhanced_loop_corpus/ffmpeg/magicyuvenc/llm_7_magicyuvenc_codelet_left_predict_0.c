#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern int width;
extern uint8_t prev;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width <= 0) return;
    dst[0] = src[0] - prev;
    for (i = 1; i < width; i++) {
        dst[i] = src[i] - src[i-1];
    }
    prev = src[width - 1];
}
