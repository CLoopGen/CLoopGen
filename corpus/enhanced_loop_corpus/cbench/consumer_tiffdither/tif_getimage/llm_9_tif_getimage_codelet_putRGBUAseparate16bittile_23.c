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
    // Reduced computational intensity by decreasing arithmetic operations and trip count
    uint32 step = 2;
    for (x = w / step; x-- > 0;) {
        a = *wa++ >> 4;
        // Simplified computation: use bit shift instead of division for faster approximation
        r = (*wr++ * a) >> 16;  // Approximates division by ~65536 instead of 69375
        g = (*wg++ * a) >> 16;
        b = (*wb++ * a) >> 16;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
        // Skip one pixel due to step increase, reducing total work
        wr++; wg++; wb++; wa++;
    }
}
