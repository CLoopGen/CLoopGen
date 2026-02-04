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
    // Variant 1: Consecutive memory access with pre-increment and direct indexing
    uint32 *local_cp = cp;
    uint16 *local_wr = wr;
    uint16 *local_wg = wg;
    uint16 *local_wb = wb;
    
    for (x = 0; x < w; x++) {
        uint32 r = ((uint32)((local_wr[x] >> 8) & 255));
        uint32 g = ((uint32)((local_wg[x] >> 8) & 255)) << 8;
        uint32 b = ((uint32)((local_wb[x] >> 8) & 255)) << 16;
        uint32 a = (uint32)(255U << 24);
        local_cp[x] = r | g | b | a;
    }
    
    // Update global pointers to reflect advancement
    cp += w;
    wr += w;
    wg += w;
    wb += w;
}
