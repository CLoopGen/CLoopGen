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
    // Variant 2: Strided memory access with stride of 2, processing every second element forward
    uint32 i;
    uint32 stride = 2;
    uint32 effective_w = w / stride;

    for (i = 0; i < effective_w; i++) {
        uint32 offset = i * stride;
        a = *(wa + offset) >> 4;
        r = (*(wr + offset) * a) / 69375;
        g = (*(wg + offset) * a) / 69375;
        b = (*(wb + offset) * a) / 69375;
        *(cp + i) = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }
}
