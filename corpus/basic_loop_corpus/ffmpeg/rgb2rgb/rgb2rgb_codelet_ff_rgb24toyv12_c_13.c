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
    for (i = 0; i < chromWidth; i++) {
        unsigned int b = src[6 * i + 0];
        unsigned int g = src[6 * i + 1];
        unsigned int r = src[6 * i + 2];
        unsigned int Y = ((ry * r + gy * g + by * b) >> 15) + 16;
        unsigned int V = ((rv * r + gv * g + bv * b) >> 15) + 128;
        unsigned int U = ((ru * r + gu * g + bu * b) >> 15) + 128;
        udst[i] = U;
        vdst[i] = V;
        ydst[2 * i] = Y;
        b = src[6 * i + 3];
        g = src[6 * i + 4];
        r = src[6 * i + 5];
        Y = ((ry * r + gy * g + by * b) >> 15) + 16;
        ydst[2 * i + 1] = Y;
    }
    ydst += lumStride;
    src += srcStride;
    if (y + 1 == height)
        break;
    for (i = 0; i < chromWidth; i++) {
        unsigned int b = src[6 * i + 0];
        unsigned int g = src[6 * i + 1];
        unsigned int r = src[6 * i + 2];
        unsigned int Y = ((ry * r + gy * g + by * b) >> 15) + 16;
        ydst[2 * i] = Y;
        b = src[6 * i + 3];
        g = src[6 * i + 4];
        r = src[6 * i + 5];
        Y = ((ry * r + gy * g + by * b) >> 15) + 16;
        ydst[2 * i + 1] = Y;
    }
    udst += chromStride;
    vdst += chromStride;
    ydst += lumStride;
    src += srcStride;
}

}
