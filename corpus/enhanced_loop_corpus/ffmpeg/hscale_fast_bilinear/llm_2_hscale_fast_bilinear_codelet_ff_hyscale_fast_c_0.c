#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int dstWidth;
extern  uint8_t *src;
extern int xInc;
extern int i;
extern unsigned int xpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop (2x unrolling) to promote sequential reads
    // This variant accesses src in a more predictable, consecutive pattern by precomputing indices
    // and partially unrolling to increase data locality and enable better vectorization.

    register unsigned int pos = xpos;
    register int i = 0;

    // Handle even number of iterations with 2x unrolling
    for (; i < dstWidth - 1; i += 2) {
        register unsigned int xx0 = pos >> 16;
        register unsigned int xalpha0 = (pos & 65535) >> 9;
        register unsigned int xx1 = (pos + xInc) >> 16;
        register unsigned int xalpha1 = ((pos + xInc) & 65535) >> 9;

        dst[i] = (src[xx0] << 7) + (src[xx0 + 1] - src[xx0]) * xalpha0;
        dst[i + 1] = (src[xx1] << 7) + (src[xx1 + 1] - src[xx1]) * xalpha1;

        pos += 2 * xInc;
    }

    // Handle remaining element if dstWidth is odd
    if (i < dstWidth) {
        register unsigned int xx = pos >> 16;
        register unsigned int xalpha = (pos & 65535) >> 9;
        dst[i] = (src[xx] << 7) + (src[xx + 1] - src[xx]) * xalpha;
    }

    // Update global xpos only if needed externally; otherwise can be removed
    xpos = pos;
}
