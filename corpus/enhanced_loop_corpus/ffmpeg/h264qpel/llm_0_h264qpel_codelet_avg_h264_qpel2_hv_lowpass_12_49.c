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
    for (int outer = 0; outer < h + 5; outer += 2) {
        for (int inner = 0; inner < 2 && (outer + inner) < h + 5; inner++) {
            int32_t *tmp_offset = tmp + inner * tmpStride;
            uint16_t *src_offset = src + inner * srcStride;
            tmp_offset[0] = (src_offset[0] + src_offset[1]) * 20 - (src_offset[-1] + src_offset[2]) * 5 + (src_offset[-2] + src_offset[3]) + pad;
            tmp_offset[1] = (src_offset[1] + src_offset[2]) * 20 - (src_offset[0] + src_offset[3]) * 5 + (src_offset[-1] + src_offset[4]) + pad;
        }
        tmp += 2 * tmpStride;
        src += 2 * srcStride;
    }
}
