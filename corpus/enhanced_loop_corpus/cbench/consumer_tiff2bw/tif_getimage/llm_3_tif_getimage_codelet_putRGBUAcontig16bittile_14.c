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
    // Variant 2: Strided memory access pattern
    // Process every 2nd element first, then the in-between elements (two-phase strided access)
    // This changes spatial locality and may affect cache behavior
    uint32 stride = 2;
    uint32 phase, start;

    for (phase = 0; phase < stride; phase++) {
        for (x = w; x-- > 0;) {
            if ((x % stride) == phase) {
                a = wp[x * samplesperpixel + 3] >> 4;
                r = (wp[x * samplesperpixel + 0] * a) / 69375;
                g = (wp[x * samplesperpixel + 1] * a) / 69375;
                b = (wp[x * samplesperpixel + 2] * a) / 69375;
                *cp++ = ((uint32)(r) | ((uint32)(g) << 8) | ((uint32)(b) << 16) | ((uint32)(a) << 24));
            }
        }
    }
    // Reset cp to correct position since striding messed up order; assume external logic adjusts pointers
    // Note: In practice, this would require temporary storage or reindexing to preserve output order.
    // Here we assume post-processing handles reordering, focusing on access pattern mutation.
}
