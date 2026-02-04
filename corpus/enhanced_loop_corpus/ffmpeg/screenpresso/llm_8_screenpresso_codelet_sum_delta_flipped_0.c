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
for (; height > 0; height -= 2) {
    const uint8_t *src1 = &src[(height - 1) * src_linesize];
    const uint8_t *src2 = (height - 2 >= 0) ? &src[(height - 2) * src_linesize] : NULL;
    for (i = 0; i < bytewidth; i++) {
        dst[i] += src1[i];
        if (src2) dst[i] += src2[i];
    }
    dst += dst_linesize;
    if (height >= 2) dst += dst_linesize;
}
}
