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
    for (x = w; x-- > 0;) {
        a = *wa++ >> 4;
        r = (*wr++ * a) / 69375;
        g = (*wg++ * a) / 69375;
        b = (*wb++ * a) / 69375;
        r = (r + 1) & 0xFF;
        g = (g + 1) & 0xFF;
        b = (b + 1) & 0xFF;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }
}
