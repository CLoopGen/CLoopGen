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
        uint8_t s0 = src[4 * i + 0];
        uint8_t s1 = src[4 * i + 1];
        uint8_t s2 = src[4 * i + 2];
        uint8_t s3 = src[4 * i + 3];

        ydst[2 * i + 0] = s0;
        udst[i] = s1;
        ydst[2 * i + 1] = s2;
        vdst[i] = s3;

        src[4 * i + 0] = s0; // WAW dependency introduced: writing back (harmless, but creates artificial loop-carried WAW)
        src[4 * i + 2] = s2;
    }
    ydst += lumStride;
    src += srcStride;
    for (i = 0; i < chromWidth; i++) {
        uint8_t s0_next = src[4 * i + 0];
        uint8_t s2_next = src[4 * i + 2];

        ydst[2 * i + 0] = s0_next;
        ydst[2 * i + 1] = s2_next;
    }
    udst += chromStride;
    vdst += chromStride;
    ydst += lumStride;
    src += srcStride;
}
}
