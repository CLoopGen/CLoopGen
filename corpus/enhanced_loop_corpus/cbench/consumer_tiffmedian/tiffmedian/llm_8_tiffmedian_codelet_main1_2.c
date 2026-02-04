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
    uint16 temp_r = rm[i];
    uint16 temp_g = gm[i];
    uint16 temp_b = bm[i];
    rm[i] = (temp_r + (temp_r << 8) + (temp_r << 4) + (temp_r << 1)) >> 8;
    gm[i] = (temp_g + (temp_g << 8) + (temp_g << 4) + (temp_g << 1)) >> 8;
    bm[i] = (temp_b + (temp_b << 8) + (temp_b << 4) + (temp_b << 1)) >> 8;
}
}
