#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; x < w; x++) {
        if ((x & 1) == 0) {
            dst[x] = src[x >> 1];
        } else {
            continue;
        }
    }
}
