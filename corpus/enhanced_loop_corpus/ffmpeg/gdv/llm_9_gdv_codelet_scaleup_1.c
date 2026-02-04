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
    for (x = 0; x < w - 3; x += 4) {
        uint8_t val0 = src[(x >> 1) + 0];
        uint8_t val1 = src[(x >> 1) + 1];
        dst[x + 0] = val0;
        dst[x + 1] = val0;
        dst[x + 2] = val1;
        dst[x + 3] = val1;
    }
}
