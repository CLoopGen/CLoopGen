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
extern uint16 *wa;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w; x += 2) {
        uint32 val1_r = ((*wr++) >> 8) & 255;
        uint32 val1_g = ((*wg++) >> 8) & 255;
        uint32 val1_b = ((*wb++) >> 8) & 255;
        uint32 val1_a = ((*wa++) >> 8) & 255;
        *cp++ = val1_r | (val1_g << 8) | (val1_b << 16) | (val1_a << 24);

        if (x + 1 < w) {
            uint32 val2_r = ((*wr++) >> 8) & 255;
            uint32 val2_g = ((*wg++) >> 8) & 255;
            uint32 val2_b = ((*wb++) >> 8) & 255;
            uint32 val2_a = ((*wa++) >> 8) & 255;
            *cp++ = val2_r | (val2_g << 8) | (val2_b << 16) | (val2_a << 24);
        }
    }
}
