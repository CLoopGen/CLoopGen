#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 rm[256];
extern uint16 gm[256];
extern uint16 bm[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; ++i) {
        rm[i] = (((rm[i]) * ((1L << 16) - 1)) / 255);
        gm[i] = (((gm[i]) * ((1L << 16) - 1)) / 255);
        bm[i] = (((bm[i]) * ((1L << 16) - 1)) / 255);
        // Introduce artificial loop-carried dependency via reuse of previous iteration's value
        if (i > 0) {
            rm[i] += rm[i-1] & 0xFFFF;  // WAW + RAW dependency introduced: current depends on prior write
            gm[i] += gm[i-1] & 0xFFFF;
            bm[i] += bm[i-1] & 0xFFFF;
        }
    }
}
