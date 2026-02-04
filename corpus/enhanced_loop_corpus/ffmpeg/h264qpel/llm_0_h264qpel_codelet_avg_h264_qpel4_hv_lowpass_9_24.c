#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
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
            int offset = outer + inner;
            int16_t *tmp_offset = tmp + offset * tmpStride;
            uint16_t *src_offset = src + offset * srcStride;

            tmp_offset[0] = (src_offset[0] + src_offset[1]) * 20 - (src_offset[-1] + src_offset[2]) * 5 + (src_offset[-2] + src_offset[3]) + pad;
            tmp_offset[1] = (src_offset[1] + src_offset[2]) * 20 - (src_offset[0] + src_offset[3]) * 5 + (src_offset[-1] + src_offset[4]) + pad;
            tmp_offset[2] = (src_offset[2] + src_offset[3]) * 20 - (src_offset[1] + src_offset[4]) * 5 + (src_offset[0] + src_offset[5]) + pad;
            tmp_offset[3] = (src_offset[3] + src_offset[4]) * 20 - (src_offset[2] + src_offset[5]) * 5 + (src_offset[1] + src_offset[6]) + pad;
        }
    }
}
