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
        uint32 r1 = ((*wr++) >> 8) & 255;
        uint32 g1 = ((*wg++) >> 8) & 255;
        uint32 b1 = ((*wb++) >> 8) & 255;
        uint32 a1 = ((*wa++) >> 8) & 255;
        *cp++ = r1 | (g1 << 8) | (b1 << 16) | (a1 << 24);

        if (x + 1 < w) {
            uint32 r2 = ((*wr++) >> 8) & 255;
            uint32 g2 = ((*wg++) >> 8) & 255;
            uint32 b2 = ((*wb++) >> 8) & 255;
            uint32 a2 = ((*wa++) >> 8) & 255;
            *cp++ = r2 | (g2 << 8) | (b2 << 16) | (a2 << 24);
        }
    }
}
