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
    uint32_t temp_g, temp_sb, temp_sr, temp_sa;
    for (j = 0; j < height; j++) {
        if (planes == 3) {
            for (i = 0; i < width; i++) {
                temp_g = sg[i];
                temp_sb = sb[i];
                temp_sr = sr[i];
                dst[0][k] = temp_g;
                temp_g += 128;
                dst[1][k] = temp_sb - temp_g;
                dst[2][k] = temp_sr - temp_g;
                k++;
            }
        } else {
            for (i = 0; i < width; i++) {
                temp_g = sg[i];
                temp_sb = sb[i];
                temp_sr = sr[i];
                temp_sa = sa[i];
                dst[0][k] = temp_g;
                temp_g += 128;
                dst[1][k] = temp_sb - temp_g;
                dst[2][k] = temp_sr - temp_g;
                dst[3][k] = temp_sa;
                k++;
            }
            sa += stride[3];
        }
        k += dst_stride - width;
        sg += stride[0];
        sb += stride[1];
        sr += stride[2];
    }
}
