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
    for (x = 0; x < w; x++) {
        uint32 r = (*wr++) & 0xFF00;
        uint32 g = (*wg++) & 0xFF00;
        uint32 b = (*wb++) & 0xFF00;
        uint32 a = (*wa++) & 0xFF00;
        *cp++ = (r >> 8) | (g) | (b << 8) | (a << 16);
    }
}
