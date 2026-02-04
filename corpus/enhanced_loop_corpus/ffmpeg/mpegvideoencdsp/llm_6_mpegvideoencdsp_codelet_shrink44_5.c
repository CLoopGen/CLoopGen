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
    s2 = s1 + src_wrap;
    s3 = s2 + src_wrap;
    s4 = s3 + src_wrap;
    d = dst;
    for (w = width; w > 0; w--) {
        uint8_t sum_low = (s1[0] + s2[0] + s3[0] + s4[0]) >> 2;
        uint8_t sum_high = (s1[3] + s2[3] + s3[3] + s4[3]) >> 2;
        uint8_t sum_mid = (s1[1] + s1[2] + s2[1] + s2[2] + 
                           s3[1] + s3[2] + s4[1] + s4[2] + 4) >> 3;
        d[0] = (sum_low + sum_mid + sum_high + 1) / 3;
        s1 += 4;
        s2 += 4;
        s3 += 4;
        s4 += 4;
        d++;
    }
    src += 4 * src_wrap;
    dst += dst_wrap;
}
}
