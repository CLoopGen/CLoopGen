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
int x1;
for (x1 = 0; x1 < w; x1++) {
    for (x = x1; x < x1 + 1; x++) {
        *dst = (*dst * tau + asrc) >> 24;
        dst += dx;
    }
}
}
