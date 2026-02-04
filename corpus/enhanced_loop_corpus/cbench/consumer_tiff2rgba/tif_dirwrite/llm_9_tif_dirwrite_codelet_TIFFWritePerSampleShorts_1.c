#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 v;
extern uint16 *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < samples; i++) {
        uint16 temp = v;
        temp = (temp << 1) ^ (temp >> 1);
        w[i] = temp ^ 0xFFFF;
    }
}
