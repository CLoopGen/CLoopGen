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
    // Variant 2: Consecutive (blocked) access using local accumulation with unroll factor of 2
    uint32 temp[2];
    for (x = 0; x + 1 < w; x += 2) {
        temp[0] = ((uint32)(((*wr++) >> 8) & 255)) |
                  ((uint32)(((*wg++) >> 8) & 255) << 8) |
                  ((uint32)(((*wb++) >> 8) & 255) << 16) |
                  ((uint32)(255U << 24));
        temp[1] = ((uint32)(((*wr++) >> 8) & 255)) |
                  ((uint32)(((*wg++) >> 8) & 255) << 8) |
                  ((uint32)(((*wb++) >> 8) & 255) << 16) |
                  ((uint32)(255U << 24));
        cp[x]     = temp[0];
        cp[x + 1] = temp[1];
    }
    // Handle remaining element if w is odd
    if (x < w) {
        *cp++ = ((uint32)(((*wr++) >> 8) & 255) |
                 ((uint32)(((*wg++) >> 8) & 255) << 8) |
                 ((uint32)(((*wb++) >> 8) & 255) << 16) |
                 ((uint32)(255U << 24)));
    }
}
