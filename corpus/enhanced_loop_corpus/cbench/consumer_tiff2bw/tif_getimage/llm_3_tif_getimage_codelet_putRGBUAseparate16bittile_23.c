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
    // Variant 2: Strided memory access (stride of 2), wrapping around bounds if needed
    const uint32 stride = 2;
    uint32 count = w / stride;

    // Reset pointers to base if assuming forward-only use; assume initial pointers are correctly set
    for (x = 0; x < count; ++x) {
        a = wa[x * stride] >> 4;
        r = (wr[x * stride] * a) / 69375;
        g = (wg[x * stride] * a) / 69375;
        b = (wb[x * stride] * a) / 69375;
        cp[x] = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }

    // Handle remaining elements if w is not divisible by stride
    for (x = w - (w % stride); x < w; ++x) {
        a = *wa++ >> 4;
        r = (*wr++ * a) / 69375;
        g = (*wg++ * a) / 69375;
        b = (*wb++ * a) / 69375;
        *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
    }
}
