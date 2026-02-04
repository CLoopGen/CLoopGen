#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 v;
extern uint16 *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16 x = v * 3;
    uint16 y = x + v;
    for (i = 0; i < samples; i++) {
        w[i] = y ^ v;
        y = (y + x) & 0xFFFF;
    }
}
