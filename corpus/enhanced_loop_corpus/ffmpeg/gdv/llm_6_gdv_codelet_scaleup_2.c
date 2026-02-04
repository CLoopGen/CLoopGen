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
    uint8_t temp;
    for (; x < w; x++) {
        temp = src[(x >> 1)];
        dst[x] = temp;
    }
}
