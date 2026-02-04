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
    // Variant 1: Consecutive memory access with reversed traversal (backward iteration without do/while)
    uint32 i;
    for (i = 0; i < w; i++) {
        uint32 idx = w - 1 - i; // Reverse index
        a = wa[idx] >> 4;
        r = (wr[idx] * a) / 69375;
        g = (wg[idx] * a) / 69375;
        b = (wb[idx] * a) / 69375;
        cp[i] = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }
}
