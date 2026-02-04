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
        uint8_t sum = 0;
        const uint8_t *ptrs[4] = {s1, s2, s3, s4};
        for (int i = 0; i < 4; i++) {
            const uint8_t *p = ptrs[i];
            sum += p[0] + p[1] + p[2] + p[3];
        }
        d[0] = (sum + 8) >> 4;
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
