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
    // Variant 2: Consecutive block access using array indexing with fixed offset
    // All arrays are accessed consecutively but starting from an offset base
    uint32 offset = 16; // Simulate processing from a shifted window
    for (x = 0; x < w; x++) {
        uint32 r = ((uint32)((wr[offset + x] >> 8) & 255));
        uint32 g = ((uint32)((wg[offset + x] >> 8) & 255) << 8);
        uint32 b = ((uint32)((wb[offset + x] >> 8) & 255) << 16);
        uint32 a = ((uint32)((wa[offset + x] >> 8) & 255) << 24);
        cp[x] = r | g | b | a;
    }
}
