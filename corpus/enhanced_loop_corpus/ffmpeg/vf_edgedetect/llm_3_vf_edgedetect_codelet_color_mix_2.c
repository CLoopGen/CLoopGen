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
    // Variant 2: Reverse Sequential Access (process array from end to beginning)
    for (j = 0; j < h; j++) {
        for (i = w - 1; i >= 0; i--)
            dst[i] = (dst[i] + src[i]) >> 1;
        dst += dst_linesize;
        src += src_linesize;
    }
}
