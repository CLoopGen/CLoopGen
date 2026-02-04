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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height > 0; height--) {
    for (w = width; w > 0; w--) {
        int tmp = 0;
        i = 0;
        for (; i < 8; i++) {
            tmp += src[0] + src[1] + src[2] + src[3] + src[4] + src[5] + src[6] + src[7];
            src += src_wrap;
        }
        *(dst++) = (tmp + 32) >> 6;
        src += 8 - 8 * src_wrap;
    }
    src += 8 * src_wrap - 8 * width;
    dst += dst_wrap - width;
}
}
