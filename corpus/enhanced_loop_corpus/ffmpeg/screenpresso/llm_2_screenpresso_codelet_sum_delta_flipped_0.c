#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int bytewidth;
extern int height;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height > 0; height--) {
    const uint8_t *src1 = &src[(height - 1) * src_linesize];
    for (i = bytewidth - 1; i >= 0; i--)
        dst[i] += src1[i];
    dst += dst_linesize;
}
}
