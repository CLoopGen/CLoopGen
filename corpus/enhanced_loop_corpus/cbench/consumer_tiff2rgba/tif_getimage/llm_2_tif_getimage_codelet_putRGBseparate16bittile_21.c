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
    // Variant 1: Strided memory access with stride of 2
    // Instead of accessing every consecutive element in wr, wg, wb,
    // we now access every second element, effectively halving the number of iterations.
    uint32 stride = 2;
    uint32 limit = w / stride;
    for (x = 0; x < limit; x++) {
        *cp++ = ((uint32)(((*wr) >> 8) & 255) | 
                 ((uint32)(((*wg) >> 8) & 255) << 8) | 
                 ((uint32)(((*wb) >> 8) & 255) << 16) | 
                 ((uint32)(255UL << 24)));
        wr += stride;
        wg += stride;
        wb += stride;
    }
}
