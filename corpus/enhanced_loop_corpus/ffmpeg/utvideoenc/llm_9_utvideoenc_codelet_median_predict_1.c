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
for (i = 0; i < width; i++) {
    uint8_t diff1 = src[i] - prev;
    uint8_t diff2 = (src[i] ^ prev) + 1;
    *dst++ = diff1 ^ diff2;
    prev = src[i] ^ diff1;
}
}
