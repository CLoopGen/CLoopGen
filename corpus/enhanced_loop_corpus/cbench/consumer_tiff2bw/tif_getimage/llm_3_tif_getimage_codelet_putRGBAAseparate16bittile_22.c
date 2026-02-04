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
    // Consecutive reverse traversal: process arrays from end to start
    uint16 *local_wr = wr + w - 1;
    uint16 *local_wg = wg + w - 1;
    uint16 *local_wb = wb + w - 1;
    uint16 *local_wa = wa + w - 1;
    uint32 *local_cp = cp + w - 1;

    for (x = 0; x < w; x++) {
        *local_cp-- = ((uint32)((( *local_wr--) >> 8) & 255) |
                       ((uint32)((( *local_wg--) >> 8) & 255) << 8) |
                       ((uint32)((( *local_wb--) >> 8) & 255) << 16) |
                       ((uint32)((( *local_wa--) >> 8) & 255) << 24));
    }
    // Update global cp pointer to reflect write position after reverse fill
    cp += w;
}
