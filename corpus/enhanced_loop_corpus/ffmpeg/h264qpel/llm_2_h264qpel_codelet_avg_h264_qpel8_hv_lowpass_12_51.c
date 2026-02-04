#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h + 5; i++) {
        int32_t *tmp_ptr = tmp;
        uint16_t *src_ptr = src;
        tmp_ptr[0] = (src_ptr[0] + src_ptr[1]) * 20 - (src_ptr[-1] + src_ptr[2]) * 5 + (src_ptr[-2] + src_ptr[3]) + pad;
        tmp_ptr[1] = (src_ptr[1] + src_ptr[2]) * 20 - (src_ptr[0] + src_ptr[3]) * 5 + (src_ptr[-1] + src_ptr[4]) + pad;
        tmp_ptr[2] = (src_ptr[2] + src_ptr[3]) * 20 - (src_ptr[1] + src_ptr[4]) * 5 + (src_ptr[0] + src_ptr[5]) + pad;
        tmp_ptr[3] = (src_ptr[3] + src_ptr[4]) * 20 - (src_ptr[2] + src_ptr[5]) * 5 + (src_ptr[1] + src_ptr[6]) + pad;
        tmp_ptr[4] = (src_ptr[4] + src_ptr[5]) * 20 - (src_ptr[3] + src_ptr[6]) * 5 + (src_ptr[2] + src_ptr[7]) + pad;
        tmp_ptr[5] = (src_ptr[5] + src_ptr[6]) * 20 - (src_ptr[4] + src_ptr[7]) * 5 + (src_ptr[3] + src_ptr[8]) + pad;
        tmp_ptr[6] = (src_ptr[6] + src_ptr[7]) * 20 - (src_ptr[5] + src_ptr[8]) * 5 + (src_ptr[4] + src_ptr[9]) + pad;
        tmp_ptr[7] = (src_ptr[7] + src_ptr[8]) * 20 - (src_ptr[6] + src_ptr[9]) * 5 + (src_ptr[5] + src_ptr[10]) + pad;
        tmp += tmpStride;
        src += srcStride;
    }
}
