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
    uint32 temp_r, temp_g, temp_b, temp_a;
    for (x = w; x-- > 0;) {
        temp_a = *wa++ >> 4;
        temp_r = (*wr++ * temp_a) / 69375;
        temp_g = (*wg++ * temp_a) / 69375;
        temp_b = (*wb++ * temp_a) / 69375;
        *cp++ = ((uint32)(temp_r) | ((uint32)(temp_g) << 8) | ((uint32)(temp_b) << 16) | ((uint32)(temp_a) << 24));
    }
}
