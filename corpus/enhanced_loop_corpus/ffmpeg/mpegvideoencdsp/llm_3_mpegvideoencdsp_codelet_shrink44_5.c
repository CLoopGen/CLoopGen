#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_wrap;
extern  uint8_t *src;
extern int src_wrap;
extern int width;
extern int height;
extern int w;
extern  uint8_t *s1;
extern  uint8_t *s2;
extern  uint8_t *s3;
extern  uint8_t *s4;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height > 0; height--) {
    s1 = src;
    d = dst;
    for (w = width; w > 0; w--) {
        int offset = w * 4 - 4; 
        d[0] = (
            s1[offset + 0] + s1[offset + 1] + s1[offset + 2] + s1[offset + 3] +
            s1[offset + src_wrap + 0] + s1[offset + src_wrap + 1] + s1[offset + src_wrap + 2] + s1[offset + src_wrap + 3] +
            s1[offset + 2*src_wrap + 0] + s1[offset + 2*src_wrap + 1] + s1[offset + 2*src_wrap + 2] + s1[offset + 2*src_wrap + 3] +
            s1[offset + 3*src_wrap + 0] + s1[offset + 3*src_wrap + 1] + s1[offset + 3*src_wrap + 2] + s1[offset + 3*src_wrap + 3] + 8
        ) >> 4;
    }
    src += 4 * src_wrap;
    dst += dst_wrap;
}
}
