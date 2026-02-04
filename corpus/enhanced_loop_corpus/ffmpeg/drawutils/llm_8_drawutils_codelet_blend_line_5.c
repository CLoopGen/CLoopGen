#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dx;
extern int w;
extern unsigned int asrc;
extern unsigned int tau;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < w; x += 2) {
    if (x + 1 < w) {
        uint8_t val1 = (*dst * tau + asrc) >> 24;
        dst += dx;
        uint8_t val2 = (*dst * tau + asrc) >> 24;
        *dst = val2;
        dst += dx;
        *dst = val1;
    } else {
        *dst = (*dst * tau + asrc) >> 24;
        dst += dx;
    }
}
}
