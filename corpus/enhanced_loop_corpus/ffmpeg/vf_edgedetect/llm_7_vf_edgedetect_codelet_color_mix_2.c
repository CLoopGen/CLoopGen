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
    for (j = 0; j < h; j++) {
        for (i = 1; i < w; i++) {
            dst[i] = (dst[i-1] + src[i]) >> 1;
        }
        if (w > 0)
            dst[0] = (dst[0] + src[0]) >> 1;
        dst += dst_linesize;
        src += src_linesize;
    }
}
