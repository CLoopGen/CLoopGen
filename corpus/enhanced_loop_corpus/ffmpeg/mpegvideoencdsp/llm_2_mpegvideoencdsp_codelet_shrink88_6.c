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
        const uint8_t *src_ptr = src;
        for (i = 0; i < 8; i++) {
            tmp += src_ptr[0] + src_ptr[1] + src_ptr[2] + src_ptr[3] +
                   src_ptr[4] + src_ptr[5] + src_ptr[6] + src_ptr[7];
            src_ptr += src_wrap;
        }
        *(dst++) = (tmp + 32) >> 6;
        src += 8;
    }
    src += 8 * src_wrap - 8 * width;
    dst += dst_wrap - width;
}
}
