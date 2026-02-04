#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern int width;
extern int i;
extern uint8_t prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_prev = prev;
    for (i = 0; i < width; i++) {
        uint8_t diff = src[i] - local_prev;
        local_prev = src[i];
        *dst++ = diff;
    }
    prev = src[width - 1];
}
