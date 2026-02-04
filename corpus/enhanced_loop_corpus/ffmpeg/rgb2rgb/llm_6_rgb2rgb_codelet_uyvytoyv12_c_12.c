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
    // First pass: process U, Y, V, Y' from first row
    for (i = 0; i < chromWidth; i++) {
        uint8_t s1 = src[4 * i + 1];
        uint8_t s3 = src[4 * i + 3];
        ydst[2 * i + 0] = s1;
        ydst[2 * i + 1] = s3;
        udst[i] = src[4 * i + 0];
        vdst[i] = src[4 * i + 2];
    }
    ydst += lumStride;
    src += srcStride;
    // Second pass: only update Y values from second row, no writes to U/V
    for (i = 0; i < chromWidth; i++) {
        uint8_t temp_y1 = src[4 * i + 1];
        uint8_t temp_y2 = src[4 * i + 3];
        ydst[2 * i + 0] = temp_y1;
        ydst[2 * i + 1] = temp_y2;
    }
    udst += chromStride;
    vdst += chromStride;
    ydst += lumStride;
    src += srcStride;
}
}
