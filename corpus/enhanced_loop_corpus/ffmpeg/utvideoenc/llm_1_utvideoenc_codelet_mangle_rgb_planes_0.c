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
if (planes == 3) {
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            g = sg[i];
            dst[0][j * dst_stride + i] = g;
            g += 128;
            dst[1][j * dst_stride + i] = sb[i] - g;
            dst[2][j * dst_stride + i] = sr[i] - g;
        }
        sg += stride[0];
        sb += stride[1];
        sr += stride[2];
    }
} else {
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            g = sg[i];
            dst[0][j * dst_stride + i] = g;
            g += 128;
            dst[1][j * dst_stride + i] = sb[i] - g;
            dst[2][j * dst_stride + i] = sr[i] - g;
            dst[3][j * dst_stride + i] = sa[i];
        }
        sg += stride[0];
        sb += stride[1];
        sr += stride[2];
        sa += stride[3];
    }
}
}
