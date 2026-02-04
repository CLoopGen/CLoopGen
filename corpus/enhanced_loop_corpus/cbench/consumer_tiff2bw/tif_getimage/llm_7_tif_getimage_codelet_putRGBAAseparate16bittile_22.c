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
    uint32 acc = 0;
    for (x = 0; x < w; x++) {
        acc += ((uint32)(((*wr++) >> 8) & 255) | ((uint32)(((*wg++) >> 8) & 255) << 8));
        acc += ((uint32)(((*wb++) >> 8) & 255) << 16);
        acc ^= ((uint32)(((*wa++) >> 8) & 255) << 24); // Introduces WAW and loop-carried dependency
        *cp++ = acc; // Data now depends on previous iteration (RAW + loop-carried)
    }
}
