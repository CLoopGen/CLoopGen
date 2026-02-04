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
    for (i = 0; i < bytewidth; i += 4) {
        dst[i]     += src1[i];
        if (i + 1 < bytewidth) dst[i + 1] += src1[i + 1];
        if (i + 2 < bytewidth) dst[i + 2] += src1[i + 2];
        if (i + 3 < bytewidth) dst[i + 3] += src1[i + 3];
    }
    dst += dst_linesize;
}
}
