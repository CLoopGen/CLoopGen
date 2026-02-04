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
    // Variant 2: Consecutive (cache-friendly) array access using local indexing without pointer arithmetic
    // Uses base pointers with offset indexing to promote predictable memory access pattern
    uint32 *local_cp = cp;
    uint16 *local_wr = wr;
    uint16 *local_wg = wg;
    uint16 *local_wb = wb;
    uint16 *local_wa = wa;

    for (x = 0; x < w; x++) {
        uint32 pixel = ((uint32)((local_wr[x] >> 8) & 255)) |
                      ((uint32)((local_wg[x] >> 8) & 255) << 8) |
                      ((uint32)((local_wb[x] >> 8) & 255) << 16) |
                      ((uint32)((local_wa[x] >> 8) & 255) << 24);
        local_cp[x] = pixel;
    }
}
