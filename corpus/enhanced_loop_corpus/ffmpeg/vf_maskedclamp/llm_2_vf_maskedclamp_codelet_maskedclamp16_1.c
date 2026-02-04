#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int undershoot;
extern int overshoot;
extern  uint16_t *bsrc;
extern  uint16_t *darksrc;
extern  uint16_t *brightsrc;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes elements at even indices first, then odd indices in a second pass
    // This changes spatial locality and may affect cache behavior

    int stride = 2;
    int remainder = w % stride;

    // First pass: process even indices
    for (int x = 0; x < w - remainder; x += stride) {
        dst[x] = ((bsrc[x]) > (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
        dst[x] = ((dst[x]) > (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
    }

    // Second pass: handle remaining elements (odd index if w is odd)
    for (int x = w - remainder; x < w; x++) {
        dst[x] = ((bsrc[x]) > (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
        dst[x] = ((dst[x]) > (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
    }
}
