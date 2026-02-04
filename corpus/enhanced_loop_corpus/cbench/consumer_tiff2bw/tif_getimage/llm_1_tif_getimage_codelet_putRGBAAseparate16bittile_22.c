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
    uint32 step = (w + 3) / 4;
    for (x = 0; x < step; x++) {
        if (x*4+0 < w) *cp++ = ((uint32)(((*wr++) >> 8) & 255) | ((uint32)(((*wg++) >> 8) & 255) << 8) | ((uint32)(((*wb++) >> 8) & 255) << 16) | ((uint32)(((*wa++) >> 8) & 255) << 24));
        if (x*4+1 < w) *cp++ = ((uint32)(((*wr++) >> 8) & 255) | ((uint32)(((*wg++) >> 8) & 255) << 8) | ((uint32)(((*wb++) >> 8) & 255) << 16) | ((uint32)(((*wa++) >> 8) & 255) << 24));
        if (x*4+2 < w) *cp++ = ((uint32)(((*wr++) >> 8) & 255) | ((uint32)(((*wg++) >> 8) & 255) << 8) | ((uint32)(((*wb++) >> 8) & 255) << 16) | ((uint32)(((*wa++) >> 8) & 255) << 24));
        if (x*4+3 < w) *cp++ = ((uint32)(((*wr++) >> 8) & 255) | ((uint32)(((*wg++) >> 8) & 255) << 8) | ((uint32)(((*wb++) >> 8) & 255) << 16) | ((uint32)(((*wa++) >> 8) & 255) << 24));
    }
}
