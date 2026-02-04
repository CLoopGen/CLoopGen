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
extern int32_t ry;
extern int32_t gy;
extern int32_t by;
extern int32_t ru;
extern int32_t gu;
extern int32_t bu;
extern int32_t rv;
extern int32_t gv;
extern int32_t bv;
extern int y;
extern  int chromWidth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    int i;
    uint8_t *src_row = src;
    uint8_t *ydst_row = ydst;
    for (i = 0; i < chromWidth * 6; i += 6) {
        unsigned int b0 = src_row[i + 0];
        unsigned int g0 = src_row[i + 1];
        unsigned int r0 = src_row[i + 2];
        unsigned int b1 = src_row[i + 3];
        unsigned int g1 = src_row[i + 4];
        unsigned int r1 = src_row[i + 5];

        unsigned int Y0 = ((ry * r0 + gy * g0 + by * b0) >> 15) + 16;
        unsigned int V = ((rv * r0 + gv * g0 + bv * b0) >> 15) + 128;
        unsigned int U = ((ru * r0 + gu * g0 + bu * b0) >> 15) + 128;

        udst[i / 6] = U;
        vdst[i / 6] = V;
        ydst_row[(i / 6) * 2 + 0] = Y0;

        unsigned int Y1 = ((ry * r1 + gy * g1 + by * b1) >> 15) + 16;
        ydst_row[(i / 6) * 2 + 1] = Y1;
    }
    ydst += lumStride;
    src += srcStride;
    if (y + 1 == height)
        break;
    for (i = 0; i < chromWidth * 6; i += 6) {
        unsigned int b0 = src[i + 0];
        unsigned int g0 = src[i + 1];
        unsigned int r0 = src[i + 2];
        unsigned int b1 = src[i + 3];
        unsigned int g1 = src[i + 4];
        unsigned int r1 = src[i + 5];

        unsigned int Y0 = ((ry * r0 + gy * g0 + by * b0) >> 15) + 16;
        unsigned int Y1 = ((ry * r1 + gy * g1 + by * b1) >> 15) + 16;

        ydst[2 * (i / 6) + 0] = Y0;
        ydst[2 * (i / 6) + 1] = Y1;
    }
    udst += chromStride;
    vdst += chromStride;
    ydst += lumStride;
    src += srcStride;
}
}
