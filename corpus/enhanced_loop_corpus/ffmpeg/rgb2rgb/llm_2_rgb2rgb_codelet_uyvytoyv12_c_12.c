#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *ydst;
extern uint8_t *udst;
extern uint8_t *vdst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int srcStride;
extern int y;
extern  int chromWidth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    int i;
    uint8_t *src_row1 = src;
    uint8_t *src_row2 = src + srcStride;
    uint8_t *ydst_row1 = ydst;
    uint8_t *ydst_row2 = ydst + lumStride;
    uint8_t *udst_cur = udst;
    uint8_t *vdst_cur = vdst;

    for (i = 0; i < chromWidth; i++) {
        int src_idx = 4 * i;
        udst_cur[i] = src_row1[src_idx + 0];
        ydst_row1[2*i + 0] = src_row1[src_idx + 1];
        vdst_cur[i] = src_row1[src_idx + 2];
        ydst_row1[2*i + 1] = src_row1[src_idx + 3];
    }

    for (i = 0; i < chromWidth; i++) {
        int src_idx = 4 * i;
        ydst_row2[2*i + 0] = src_row2[src_idx + 1];
        ydst_row2[2*i + 1] = src_row2[src_idx + 3];
    }

    udst += chromStride;
    vdst += chromStride;
    ydst += 2 * lumStride;
    src += 2 * srcStride;
}
}
