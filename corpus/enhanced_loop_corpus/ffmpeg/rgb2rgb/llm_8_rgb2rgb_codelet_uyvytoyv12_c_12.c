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
for (y = 0; y < height; y += 4) {
    int i;
    // First row: full YUV422 unpacking
    for (i = 0; i < chromWidth; i++) {
        udst[i] = src[4 * i + 0];
        ydst[2 * i + 0] = src[4 * i + 1];
        vdst[i] = src[4 * i + 2];
        ydst[2 * i + 1] = src[4 * i + 3];
    }
    ydst += lumStride;
    src += srcStride;

    // Second row: only update luma
    for (i = 0; i < chromWidth; i++) {
        ydst[2 * i + 0] = src[4 * i + 1];
        ydst[2 * i + 1] = src[4 * i + 3];
    }
    udst += chromStride;
    vdst += chromStride;
    ydst += lumStride;
    src += srcStride;

    // Third row: skip if not available
    if (y + 2 < height) {
        for (i = 0; i < chromWidth; i++) {
            ydst[2 * i + 0] = src[4 * i + 1];
            ydst[2 * i + 1] = src[4 * i + 3];
        }
        ydst += lumStride;
        src += srcStride;
    }

    // Fourth row: skip if not available
    if (y + 3 < height) {
        for (i = 0; i < chromWidth; i++) {
            ydst[2 * i + 0] = src[4 * i + 1];
            ydst[2 * i + 1] = src[4 * i + 3];
        }
        ydst += lumStride;
        src += srcStride;
    }
}
}
