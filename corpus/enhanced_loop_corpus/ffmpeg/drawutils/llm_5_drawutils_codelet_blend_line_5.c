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
for (x = 0; x < w; x++) {
    if (x % 2 == 0) {
        *dst = (*dst * tau + asrc) >> 24;
    } else {
        *dst = (*dst * (tau >> 1) + asrc) >> 24;
    }
    dst += dx;
}
}
