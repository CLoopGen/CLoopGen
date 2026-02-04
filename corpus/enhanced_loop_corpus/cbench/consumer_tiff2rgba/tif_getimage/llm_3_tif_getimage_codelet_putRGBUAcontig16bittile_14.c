#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 *cp;
extern uint32 x;
extern uint32 w;
extern int samplesperpixel;
extern uint16 *wp;
extern uint32 r;
extern uint32 g;
extern uint32 b;
extern uint32 a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided array access using index scaling instead of pointer arithmetic
    for (x = 0; x < w; x++) {
        uint32 idx = x * samplesperpixel;
        a = wp[idx + 3] >> 4;
        r = (wp[idx + 0] * a) / 69375;
        g = (wp[idx + 1] * a) / 69375;
        b = (wp[idx + 2] * a) / 69375;
        cp[x] = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }
}
