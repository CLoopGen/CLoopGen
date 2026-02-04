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
for (; height > 0; --height) {
    w = width;
    if (w <= 0) continue;
    do {
        int tmp = 0;
        for (i = 0; i < 8; i++) {
            tmp += src[0]; tmp += src[1]; tmp += src[2]; tmp += src[3];
            tmp += src[4]; tmp += src[5]; tmp += src[6]; tmp += src[7];
            src += src_wrap;
        }
        uint8_t val = (tmp + 32) >> 6;
        if (val >= 16 && val <= 240) {
            *(dst++) = val;
        } else {
            *(dst++) = 128;
        }
        src += 8 - 8 * src_wrap;
        w--;
    } while (w > 0);
    src += 8 * src_wrap - 8 * width;
    dst += dst_wrap - width;
}
}
