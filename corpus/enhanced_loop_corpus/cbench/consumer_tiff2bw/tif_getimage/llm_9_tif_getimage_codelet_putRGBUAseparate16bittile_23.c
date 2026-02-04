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
for (x = w >> 1; x-- > 0;) {          // Reduce trip count by half to increase per-iteration work
    a = *wa++ >> 4;
    uint32 a2 = *wa++ >> 4;           // Process two pixels per iteration
    r = (*wr++ * a) / 69375;
    r = (*wr++ * a2) / 69375;
    g = (*wg++ * a) / 69375;
    g = (*wg++ * a2) / 69375;
    b = (*wb++ * a) / 69375;
    b = (*wb++ * a2) / 69375;
    *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a2) << 24));
}
}
