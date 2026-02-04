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
    for (x = 0; x < w; x++) {
        uint32 local_a = wa[x] >> 4;
        uint32 local_r = (wr[x] * local_a) / 69375;
        uint32 local_g = (wg[x] * local_a) / 69375;
        uint32 local_b = (wb[x] * local_a) / 69375;
        cp[x] = (local_r | (local_g << 8) | (local_b << 16) | (local_a << 24));
    }
}
