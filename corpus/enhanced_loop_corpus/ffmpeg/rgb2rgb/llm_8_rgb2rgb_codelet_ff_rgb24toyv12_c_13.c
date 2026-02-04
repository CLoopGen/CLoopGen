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
for (y = 0; y < height; y++) {
    int i;
    for (i = 0; i < chromWidth; i += 2) {
        unsigned int b0 = src[6 * i + 0];
        unsigned int g0 = src[6 * i + 1];
        unsigned int r0 = src[6 * i + 2];
        unsigned int Y0 = ((ry * r0 + gy * g0 + by * b0) >> 15) + 16;
        unsigned int U0 = ((ru * r0 + gu * g0 + bu * b0) >> 15) + 128;
        unsigned int V0 = ((rv * r0 + gv * g0 + bv * b0) >> 15) + 128;

        unsigned int b1 = src[6 * i + 3];
        unsigned int g1 = src[6 * i + 4];
        unsigned int r1 = src[6 * i + 5];
        unsigned int Y1 = ((ry * r1 + gy * g1 + by * b1) >> 15) + 16;

        ydst[2 * i] = Y0;
        ydst[2 * i + 1] = Y1;
        udst[i] = U0;
        vdst[i] = V0;

        if (i + 1 < chromWidth) {
            b0 = src[6 * (i + 1) + 0];
            g0 = src[6 * (i + 1) + 1];
            r0 = src[6 * (i + 1) + 2];
            Y0 = ((ry * r0 + gy * g0 + by * b0) >> 15) + 16;
            U0 = ((ru * r0 + gu * g0 + bu * b0) >> 15) + 128;
            V0 = ((rv * r0 + gv * g0 + bv * b0) >> 15) + 128;

            b1 = src[6 * (i + 1) + 3];
            g1 = src[6 * (i + 1) + 4];
            r1 = src[6 * (i + 1) + 5];
            Y1 = ((ry * r1 + gy * g1 + by * b1) >> 15) + 16;

            ydst[2 * (i + 1)] = Y0;
            ydst[2 * (i + 1) + 1] = Y1;
            udst[i + 1] = U0;
            vdst[i + 1] = V0;
        }
    }
    ydst += lumStride;
    src += srcStride;
    if (y % 2 == 1) {
        udst += chromStride;
        vdst += chromStride;
    }
}
}
