#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    int stride = 2;
    for (j = 0; j < h; j++) {
        // Process elements with stride
        for (i = 0; i < w - 1; i += stride)
            dst[i] = (dst[i] + src[i]) >> 1;
        // Handle last element if width is odd
        if (w % 2 == 1)
            dst[w - 1] = (dst[w - 1] + src[w - 1]) >> 1;
        dst += dst_linesize;
        src += src_linesize;
    }
}
