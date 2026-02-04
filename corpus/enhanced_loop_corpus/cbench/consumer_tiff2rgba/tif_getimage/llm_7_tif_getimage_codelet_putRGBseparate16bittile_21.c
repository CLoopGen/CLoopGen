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
    uint32 local_accum = 0;
    for (x = 0; x < w; x += 2) {
        if (x + 1 < w) {
            local_accum = ((uint32)(((*wr++) >> 8) & 255)) |
                          ((uint32)(((*wg++) >> 8) & 255) << 8) |
                          ((uint32)(((*wb++) >> 8) & 255) << 16) |
                          ((uint32)(255U << 24));
            *cp++ = local_accum;

            local_accum = ((uint32)(((*wr++) >> 8) & 255)) |
                          ((uint32)(((*wg++) >> 8) & 255) << 8) |
                          ((uint32)(((*wb++) >> 8) & 255) << 16) |
                          ((uint32)(255U << 24));
            *cp++ = local_accum;
        } else {
            *cp++ = ((uint32)(((*wr++) >> 8) & 255) | 
                     ((uint32)(((*wg++) >> 8) & 255) << 8) | 
                     ((uint32)(((*wb++) >> 8) & 255) << 16) | 
                     ((uint32)(255U << 24)));
        }
    }
}
