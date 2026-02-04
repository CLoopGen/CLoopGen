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
    // Variant 2: Strided memory access — process every 2nd element (stride of 2)
    // This changes access pattern to non-consecutive, reducing memory bandwidth usage
    uint32 stride = 2;
    uint32 n = w / stride;  // Adjust loop bound due to striding
    for (x = 0; x < n; x++) {
        uint32 idx = x * stride;
        *cp++ = ((uint32)((wr[idx] >> 8) & 255) |
                 ((uint32)((wg[idx] >> 8) & 255) << 8) |
                 ((uint32)((wb[idx] >> 8) & 255) << 16) |
                 ((uint32)((wa[idx] >> 8) & 255) << 24));
    }
}
