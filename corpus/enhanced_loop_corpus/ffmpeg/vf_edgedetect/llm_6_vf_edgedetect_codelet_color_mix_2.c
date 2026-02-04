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
        uint8_t temp[w];
        for (i = 0; i < w; i++)
            temp[i] = (dst[i] + src[i]) >> 1;
        for (i = 0; i < w; i++)
            dst[i] = temp[i];
        dst += dst_linesize;
        src += src_linesize;
    }
}
