#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint8_t *dst_ptr = dst;
        uint8_t *src_ptr = src;
        dst_ptr[0] = (((dst_ptr[0]) + cm[(((src_ptr[0] + src_ptr[1]) * 20 - (src_ptr[0] + src_ptr[2]) * 6 + (src_ptr[1] + src_ptr[3]) * 3 - (src_ptr[2] + src_ptr[4])) + 16) >> 5] + 1) >> 1);
        dst_ptr[1] = (((dst_ptr[1]) + cm[(((src_ptr[1] + src_ptr[2]) * 20 - (src_ptr[0] + src_ptr[3]) * 6 + (src_ptr[0] + src_ptr[4]) * 3 - (src_ptr[1] + src_ptr[5])) + 16) >> 5] + 1) >> 1);
        dst_ptr[2] = (((dst_ptr[2]) + cm[(((src_ptr[2] + src_ptr[3]) * 20 - (src_ptr[1] + src_ptr[4]) * 6 + (src_ptr[0] + src_ptr[5]) * 3 - (src_ptr[0] + src_ptr[6])) + 16) >> 5] + 1) >> 1);
        dst_ptr[3] = (((dst_ptr[3]) + cm[(((src_ptr[3] + src_ptr[4]) * 20 - (src_ptr[2] + src_ptr[5]) * 6 + (src_ptr[1] + src_ptr[6]) * 3 - (src_ptr[0] + src_ptr[7])) + 16) >> 5] + 1) >> 1);
        dst_ptr[4] = (((dst_ptr[4]) + cm[(((src_ptr[4] + src_ptr[5]) * 20 - (src_ptr[3] + src_ptr[6]) * 6 + (src_ptr[2] + src_ptr[7]) * 3 - (src_ptr[1] + src_ptr[8])) + 16) >> 5] + 1) >> 1);
        dst_ptr[5] = (((dst_ptr[5]) + cm[(((src_ptr[5] + src_ptr[6]) * 20 - (src_ptr[4] + src_ptr[7]) * 6 + (src_ptr[3] + src_ptr[8]) * 3 - (src_ptr[2] + src_ptr[8])) + 16) >> 5] + 1) >> 1);
        dst_ptr[6] = (((dst_ptr[6]) + cm[(((src_ptr[6] + src_ptr[7]) * 20 - (src_ptr[5] + src_ptr[8]) * 6 + (src_ptr[4] + src_ptr[8]) * 3 - (src_ptr[3] + src_ptr[7])) + 16) >> 5] + 1) >> 1);
        dst_ptr[7] = (((dst_ptr[7]) + cm[(((src_ptr[7] + src_ptr[8]) * 20 - (src_ptr[6] + src_ptr[8]) * 6 + (src_ptr[5] + src_ptr[7]) * 3 - (src_ptr[4] + src_ptr[6])) + 16) >> 5] + 1) >> 1);
        
        dst += dstStride;
        src += srcStride;
    }
}
