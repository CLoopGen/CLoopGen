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
extern uint32 r;
extern uint32 g;
extern uint32 b;
extern uint32 a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 local_accum = 0;
    for (x = w; x-- > 0;) {
        a = *wa++ >> 4;
        r = (*wr++ * a + local_accum) / 69375;
        g = (*wg++ * a + local_accum) / 69375;
        b = (*wb++ * a + local_accum) / 69375;
        local_accum = (r + g + b) & 0xFF;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }
}
