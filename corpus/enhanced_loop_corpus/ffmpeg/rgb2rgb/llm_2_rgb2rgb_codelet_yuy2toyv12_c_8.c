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
    uint8_t *ydst_row1 = ydst;
    uint8_t *udst_ptr = udst;
    uint8_t *vdst_ptr = vdst;
    for (i = 0; i < chromWidth; i++) {
        // Access memory with consecutive loads and stores to improve spatial locality
        uint8_t s0 = src_row1[4*i + 0];
        uint8_t s1 = src_row1[4*i + 1];
        uint8_t s2 = src_row1[4*i + 2];
        uint8_t s3 = src_row1[4*i + 3];

        ydst_row1[2*i + 0] = s0;
        ydst_row1[2*i + 1] = s2;
        udst_ptr[i] = s1;
        vdst_ptr[i] = s3;
    }
    // Move to next source and luminance rows
    src += srcStride;
    ydst += lumStride;

    uint8_t *src_row2 = src;
    uint8_t *ydst_row2 = ydst;
    for (i = 0; i < chromWidth; i++) {
        // Reuse same access pattern but only write luma components
        uint8_t s0 = src_row2[4*i + 0];
        uint8_t s2 = src_row2[4*i + 2];

        ydst_row2[2*i + 0] = s0;
        ydst_row2[2*i + 1] = s2;
    }

    udst += chromStride;
    vdst += chromStride;
    ydst += lumStride;
    src += srcStride;
}
}
