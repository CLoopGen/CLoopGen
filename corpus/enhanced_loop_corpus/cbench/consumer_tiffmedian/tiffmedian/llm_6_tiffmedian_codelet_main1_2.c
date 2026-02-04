#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 rm[256];
extern uint16 gm[256];
extern uint16 bm[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16 temp_r, temp_g, temp_b;
    for (i = 0; i < 256; ++i) {
        temp_r = (((rm[i]) * ((1L << 16) - 1)) / 255);
        temp_g = (((gm[i]) * ((1L << 16) - 1)) / 255);
        temp_b = (((bm[i]) * ((1L << 16) - 1)) / 255);
        rm[i] = temp_r;
        gm[i] = temp_g;
        bm[i] = temp_b;
    }
}
