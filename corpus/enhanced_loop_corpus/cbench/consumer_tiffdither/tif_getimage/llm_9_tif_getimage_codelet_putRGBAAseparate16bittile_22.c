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
    for (x = 0; x < (w >> 2); x++) {
        uint32 r0 = ((*wr++) >> 8) & 255;
        uint32 g0 = ((*wg++) >> 8) & 255;
        uint32 b0 = ((*wb++) >> 8) & 255;
        uint32 a0 = ((*wa++) >> 8) & 255;
        
        uint32 r1 = ((*wr++) >> 8) & 255;
        uint32 g1 = ((*wg++) >> 8) & 255;
        uint32 b1 = ((*wb++) >> 8) & 255;
        uint32 a1 = ((*wa++) >> 8) & 255;

        uint32 r2 = ((*wr++) >> 8) & 255;
        uint32 g2 = ((*wg++) >> 8) & 255;
        uint32 b2 = ((*wb++) >> 8) & 255;
        uint32 a2 = ((*wa++) >> 8) & 255;

        uint32 r3 = ((*wr++) >> 8) & 255;
        uint32 g3 = ((*wg++) >> 8) & 255;
        uint32 b3 = ((*wb++) >> 8) & 255;
        uint32 a3 = ((*wa++) >> 8) & 255;

        *cp++ = r0 | (g0 << 8) | (b0 << 16) | (a0 << 24);
        *cp++ = r1 | (g1 << 8) | (b1 << 16) | (a1 << 24);
        *cp++ = r2 | (g2 << 8) | (b2 << 16) | (a2 << 24);
        *cp++ = r3 | (g3 << 8) | (b3 << 16) | (a3 << 24);
    }
}
