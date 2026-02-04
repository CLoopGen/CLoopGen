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
    uint8_t *row_start = src;
    for (w = width; w > 0; w--) {
        int tmp = 0;
        for (i = 0; i < 8; i++) {
            const uint8_t *s = &src[i * src_wrap];
            tmp += s[0] + s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7];
        }
        *(dst++) = (tmp + 32) >> 6;
        row_start += 8;
        src = row_start;
    }
    src += 8 * src_wrap - 8 * width;
    dst += dst_wrap - width;
}
}
