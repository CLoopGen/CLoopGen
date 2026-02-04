#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t prev = 0;
    for (; i < w; i++) {
        uint16_t sum = (dst[i] + src[i] + prev) & mask;
        dst[i] = sum;
        prev = sum;
    }
}
