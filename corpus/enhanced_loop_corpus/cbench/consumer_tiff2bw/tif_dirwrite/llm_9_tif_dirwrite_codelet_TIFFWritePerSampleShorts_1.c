#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 v;
extern uint16 *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16 temp = v * 2 - (v >> 1);
    for (i = 0; i < samples * 3; i++) {
        w[i % samples] += temp;
    }
}
