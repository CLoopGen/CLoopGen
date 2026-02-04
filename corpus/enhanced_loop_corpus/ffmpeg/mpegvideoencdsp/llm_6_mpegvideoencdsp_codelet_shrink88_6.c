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
        uint8_t *local_src = src;
        for (i = 0; i < 8; i++) {
            tmp += local_src[0] + local_src[1] + local_src[2] + local_src[3] +
                   local_src[4] + local_src[5] + local_src[6] + local_src[7];
            local_src += src_wrap;
        }
        *(dst++) = (tmp + 32) >> 6;
        src += 8;
    }
    src += 8 * src_wrap - 8 * width;
    dst += dst_wrap - width;
}
}
