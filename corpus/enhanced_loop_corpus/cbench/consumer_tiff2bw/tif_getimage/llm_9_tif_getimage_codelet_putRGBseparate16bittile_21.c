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
    for (x = 0; x < w; x++) {
        uint32 r = (*wr++) >> 8;
        uint32 g = (*wg++) >> 8;
        uint32 b = (*wb++) >> 8;
        *cp++ = (r & 255) | ((g & 255) << 8) | ((b & 255) << 16) | (0xFFU << 24);
    }
}
