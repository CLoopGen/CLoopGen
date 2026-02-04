#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst[4];
extern ptrdiff_t dst_stride;
extern int planes;
extern  int stride[4];
extern int width;
extern int height;
extern int i;
extern int j;
extern int k;
extern  uint8_t *sg;
extern  uint8_t *sb;
extern  uint8_t *sr;
extern  uint8_t *sa;
extern unsigned int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < height; j++) {
        uint8_t *dst0 = dst[0] + k;
        uint8_t *dst1 = dst[1] + k;
        uint8_t *dst2 = dst[2] + k;
        const int sg_offset = 0;
        const int sb_offset = 0;
        const int sr_offset = 0;

        if (planes == 3) {
            for (i = 0; i < width; i++) {
                g = sg[i];
                dst0[i] = g;
                g += 128;
                dst1[i] = sb[i] - g;
                dst2[i] = sr[i] - g;
            }
        } else {
            uint8_t *dst3 = dst[3] + k;
            for (i = 0; i < width; i++) {
                g = sg[i];
                dst0[i] = g;
                g += 128;
                dst1[i] = sb[i] - g;
                dst2[i] = sr[i] - g;
                dst3[i] = sa[i];
            }
            sa += stride[3];
        }
        k += dst_stride;
        sg += stride[0];
        sb += stride[1];
        sr += stride[2];
    }
}
