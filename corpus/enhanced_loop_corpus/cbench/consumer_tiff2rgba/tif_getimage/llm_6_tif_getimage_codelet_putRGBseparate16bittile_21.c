#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 *cp;
extern uint32 x;
extern uint32 w;
extern uint16 *wr;
extern uint16 *wg;
extern uint16 *wb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 temp_r, temp_g, temp_b;
    for (x = 0; x < w; x++) {
        temp_r = ((*wr++) >> 8) & 255;
        temp_g = ((*wg++) >> 8) & 255;
        temp_b = ((*wb++) >> 8) & 255;
        *cp++ = (uint32)(temp_r | (temp_g << 8) | (temp_b << 16) | (255U << 24));
    }
}
