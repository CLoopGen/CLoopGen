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
    // Variant 2: Strided memory access — treat wp as a planar (interleaved by channel) array
    // Assume input layout: [R0,R1,...,Rn, G0,G1,...,Gn, B0,B1,...,Bn, A0,A1,...,An]
    uint32 stride = w; // Each channel block has 'w' elements
    uint32 offset;
    uint32 *local_cp = cp;
    for (x = w; x-- > 0;) {
        offset = x; // Strided index: each pixel is separated by full-channel blocks
        a = ((uint16*)wp)[offset + 3*stride] >> 4;
        r = (((uint16*)wp)[offset + 0*stride] * a) / 69375;
        g = (((uint16*)wp)[offset + 1*stride] * a) / 69375;
        b = (((uint16*)wp)[offset + 2*stride] * a) / 69375;
        *local_cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }
    cp = local_cp;
}
