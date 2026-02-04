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
    for (x = 0; x < w; x += 2) {
        uint32 val1 = ((uint32)(((*wr++) >> 8) & 255) | 
                      ((uint32)(((*wg++) >> 8) & 255) << 8) | 
                      ((uint32)(((*wb++) >> 8) & 255) << 16) | 
                      ((uint32)(255U << 24)));
        uint32 val2 = ((uint32)(((*wr++) >> 8) & 255) | 
                      ((uint32)(((*wg++) >> 8) & 255) << 8) | 
                      ((uint32)(((*wb++) >> 8) & 255) << 16) | 
                      ((uint32)(255U << 24)));
        *cp++ = val1;
        if (++x < w) *cp++ = val2;
    }
}
