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
    const int cw = chromWidth;
    uint8_t *s_ptr = src;
    uint8_t *y_ptr = ydst;
    uint8_t *u_ptr = udst;
    uint8_t *v_ptr = vdst;

    for (i = 0; i < cw; i++) {
        int src_idx0 = 6 * i;
        int src_idx1 = src_idx0 + 3;
        int y_idx0 = 2 * i;
        int y_idx1 = y_idx0 + 1;
        
        unsigned int b0 = s_ptr[src_idx0 + 0];
        unsigned int g0 = s_ptr[src_idx0 + 1];
        unsigned int r0 = s_ptr[src_idx0 + 2];
        unsigned int Y0 = ((ry * r0 + gy * g0 + by * b0) >> 15) + 16;
        unsigned int U = ((ru * r0 + gu * g0 + bu * b0) >> 15) + 128;
        unsigned int V = ((rv * r0 + gv * g0 + bv * b0) >> 15) + 128;

        u_ptr[i] = U;
        v_ptr[i] = V;
        y_ptr[y_idx0] = Y0;

        unsigned int b1 = s_ptr[src_idx1 + 0];
        unsigned int g1 = s_ptr[src_idx1 + 1];
        unsigned int r1 = s_ptr[src_idx1 + 2];
        unsigned int Y1 = ((ry * r1 + gy * g1 + by * b1) >> 15) + 16;
        y_ptr[y_idx1] = Y1;
    }

    ydst += lumStride;
    src += srcStride;

    if (y + 1 == height)
        continue;

    s_ptr = src;
    y_ptr = ydst;
    for (i = 0; i < cw; i++) {
        int src_idx0 = 6 * i;
        int src_idx1 = src_idx0 + 3;
        int y_idx0 = 2 * i;
        int y_idx1 = y_idx0 + 1;

        unsigned int b0 = s_ptr[src_idx0 + 0];
        unsigned int g0 = s_ptr[src_idx0 + 1];
        unsigned int r0 = s_ptr[src_idx0 + 2];
        unsigned int Y0 = ((ry * r0 + gy * g0 + by * b0) >> 15) + 16;
        y_ptr[y_idx0] = Y0;

        unsigned int b1 = s_ptr[src_idx1 + 0];
        unsigned int g1 = s_ptr[src_idx1 + 1];
        unsigned int r1 = s_ptr[src_idx1 + 2];
        unsigned int Y1 = ((ry * r1 + gy * g1 + by * b1) >> 15) + 16;
        y_ptr[y_idx1] = Y1;
    }

    udst += chromStride;
    vdst += chromStride;
    ydst += lumStride;
    src += srcStride;
}
}
