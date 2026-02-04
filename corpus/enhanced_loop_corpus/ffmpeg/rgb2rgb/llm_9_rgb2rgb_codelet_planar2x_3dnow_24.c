#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < srcWidth - 1; x++) {
        uint8_t s = src[x];
        uint8_t t = src[x + 1];
        dst[2 * x + 1] = (s + (s << 1) + t) >> 2;
        dst[2 * x + 2] = (s + (t << 1) + t) >> 2;
    }
}
