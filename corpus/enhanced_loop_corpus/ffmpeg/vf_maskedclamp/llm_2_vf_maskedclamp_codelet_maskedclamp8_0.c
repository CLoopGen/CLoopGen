#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int undershoot;
extern int overshoot;
extern  uint8_t *bsrc;
extern  uint8_t *darksrc;
extern  uint8_t *brightsrc;
extern uint8_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    // This variant processes elements at even indices first, then odd indices in a second pass
    int stride = 2;
    for (int x = 0; x < w; x += stride) {
        if (x + 1 < w) {
            // Process two elements per iteration: x and x+1
            dst[x] = ((bsrc[x]) > (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
            dst[x] = ((dst[x]) > (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));

            dst[x+1] = ((bsrc[x+1]) > (darksrc[x+1] - undershoot) ? (bsrc[x+1]) : (darksrc[x+1] - undershoot));
            dst[x+1] = ((dst[x+1]) > (brightsrc[x+1] + overshoot) ? (brightsrc[x+1] + overshoot) : (dst[x+1]));
        } else {
            // Handle last element if width is odd
            dst[x] = ((bsrc[x]) > (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
            dst[x] = ((dst[x]) > (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
        }
    }
}
