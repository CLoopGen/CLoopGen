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
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height > 0; height--) {
    d = dst;
    int offset = 0;
    for (w = width; w >= 4; w -= 4) {
        int idx1 = offset;
        int idx2 = offset + src_wrap;
        d[0] = (src[idx1+0] + src[idx1+1] + src[idx2+0] + src[idx2+1] + 2) >> 2;
        d[1] = (src[idx1+2] + src[idx1+3] + src[idx2+2] + src[idx2+3] + 2) >> 2;
        d[2] = (src[idx1+4] + src[idx1+5] + src[idx2+4] + src[idx2+5] + 2) >> 2;
        d[3] = (src[idx1+6] + src[idx1+7] + src[idx2+6] + src[idx2+7] + 2) >> 2;
        offset += 8;
        d += 4;
    }
    for (; w > 0; w--) {
        int idx1 = offset;
        int idx2 = offset + src_wrap;
        d[0] = (src[idx1+0] + src[idx1+1] + src[idx2+0] + src[idx2+1] + 2) >> 2;
        offset += 2;
        d++;
    }
    src += 2 * src_wrap;
    dst += dst_wrap;
}
}
