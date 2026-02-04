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
    // Variant 2: Consecutive reverse traversal from the end of input arrays
    // Access elements starting from the end and move backward consecutively.
    // Assumes wr, wg, wb point to the beginning originally; adjust base pointers accordingly.
    uint32 offset = w - 1;
    for (x = 0; x < w; x++) {
        uint32 idx = offset - x; // Reverse index
        *cp++ = ((uint32)(((wr[idx]) >> 8) & 255) | 
                 ((uint32)(((wg[idx]) >> 8) & 255) << 8) | 
                 ((uint32)(((wb[idx]) >> 8) & 255) << 16) | 
                 ((uint32)(255UL << 24)));
    }
}
