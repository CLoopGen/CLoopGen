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
    s1 = src;
    s2 = s1 + src_wrap;
    d = dst;
    for (w = width; w >= 4; w -= 4) {
        uint8_t val0 = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
        uint8_t val1 = (s1[2] + s1[3] + s2[2] + s2[3] + 2) >> 2;
        uint8_t val2 = (s1[4] + s1[5] + s2[4] + s2[5] + 2) >> 2;
        uint8_t val3 = (s1[6] + s1[7] + s2[6] + s2[7] + 2) >> 2;
        *d++ = val0;
        *d++ = val1;
        *d++ = val2;
        *d++ = val3;
        s1 += 8;
        s2 += 8;
    }
    for (; w > 0; w--) {
        *d++ = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
        s1 += 2;
        s2 += 2;
    }
    src += 2 * src_wrap;
    dst += dst_wrap;
}
}
