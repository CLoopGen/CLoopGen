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
    for (i = 0; i < chromWidth; i++) {
        ydst[2 * i + 0] = src[4 * i + 0];
        udst[i] = src[4 * i + 1];
        ydst[2 * i + 1] = src[4 * i + 2];
        vdst[i] = src[4 * i + 3];
        ydst[2 * i + lumStride + 0] = src[4 * i + srcStride + 0];
        ydst[2 * i + lumStride + 1] = src[4 * i + srcStride + 2];
    }
    udst += chromStride;
    vdst += chromStride;
    ydst += 2 * lumStride;
    src += 2 * srcStride;
}
}
