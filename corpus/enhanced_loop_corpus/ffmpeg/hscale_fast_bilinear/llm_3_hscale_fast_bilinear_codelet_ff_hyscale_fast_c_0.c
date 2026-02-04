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
    // Variant 2: Strided memory access – simulate non-unit stride over dst and src
    // Introduce a fixed stride (e.g., every 2nd pixel) to create strided writes to dst
    // and slightly adjusted sampling from src to reflect irregular access pattern.
    // This models use cases like downsampling or processing subregions.

    const int stride = 2;  // Process every 2nd destination pixel
    register unsigned int pos = xpos;

    for (int idx = 0; idx < dstWidth; idx += stride) {
        register unsigned int xx = pos >> 16;
        register unsigned int xalpha = (pos & 65535) >> 9;

        // Write to strided location in dst
        dst[idx] = (src[xx] << 7) + (src[xx + 1] - src[xx]) * xalpha;

        // Advance position normally — maintains continuous sampling from src
        pos += xInc * stride;
    }

    // Update global state if used outside
    xpos = pos;
}
