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
    for (x = 0; x < w && (x % 3) == 0; x++) {
        uint32 r = (*wr++) >> 8;
        uint32 g = (*wg++) >> 8;
        uint32 b = (*wb++) >> 8;
        uint32 a = (*wa++) >> 8;
        *cp++ = (r & 255) | ((g & 255) << 8) | ((b & 255) << 16) | ((a & 255) << 24);
        x++; // Skip next iteration to reduce effective trip count
    }
}
