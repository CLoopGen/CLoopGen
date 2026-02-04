#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src;
extern int dst_stridea;
extern int dst_strideb;
extern int src_stridea;
extern int src_strideb;
extern int add;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int src_idx[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    const int dst_idx[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    const float x00 = 1.41421354F * src[src_idx[0] * src_stridea];
    const float x01 = 1.3870399F * src[src_idx[1] * src_stridea] + 0.27589938F * src[src_idx[7] * src_stridea];
    const float x02 = 1.30656302F * src[src_idx[2] * src_stridea] + 0.541196108F * src[src_idx[6] * src_stridea];
    const float x03 = 1.17587554F * src[src_idx[3] * src_stridea] + 0.785694956F * src[src_idx[5] * src_stridea];
    const float x04 = 1.41421354F * src[src_idx[4] * src_stridea];
    const float x05 = -0.785694956F * src[src_idx[3] * src_stridea] + 1.17587554F * src[src_idx[5] * src_stridea];
    const float x06 = 0.541196108F * src[src_idx[2] * src_stridea] - 1.30656302F * src[src_idx[6] * src_stridea];
    const float x07 = -0.27589938F * src[src_idx[1] * src_stridea] + 1.3870399F * src[src_idx[7] * src_stridea];
    const float x09 = x00 + x04;
    const float x0a = x01 + x03;
    const float x0b = 1.41421354F * x02;
    const float x0c = x00 - x04;
    const float x0d = x01 - x03;
    const float x0e = 0.353553385F * (x09 - x0b);
    const float x0f = 0.353553385F * (x0c + x0d);
    const float x10 = 0.353553385F * (x0c - x0d);
    const float x11 = 1.41421354F * x06;
    const float x12 = x05 + x07;
    const float x13 = x05 - x07;
    const float x14 = 0.353553385F * (x11 + x12);
    const float x15 = 0.353553385F * (x11 - x12);
    const float x16 = 0.5F * x13;
    dst[dst_idx[0] * dst_stridea] = (add ? dst[dst_idx[0] * dst_stridea] : 0) + 0.25F * (x09 + x0b) + 0.353553385F * x0a;
    dst[dst_idx[1] * dst_stridea] = (add ? dst[dst_idx[1] * dst_stridea] : 0) + 0.707106769F * (x0f + x15);
    dst[dst_idx[2] * dst_stridea] = (add ? dst[dst_idx[2] * dst_stridea] : 0) + 0.707106769F * (x0f - x15);
    dst[dst_idx[3] * dst_stridea] = (add ? dst[dst_idx[3] * dst_stridea] : 0) + 0.707106769F * (x0e + x16);
    dst[dst_idx[4] * dst_stridea] = (add ? dst[dst_idx[4] * dst_stridea] : 0) + 0.707106769F * (x0e - x16);
    dst[dst_idx[5] * dst_stridea] = (add ? dst[dst_idx[5] * dst_stridea] : 0) + 0.707106769F * (x10 - x14);
    dst[dst_idx[6] * dst_stridea] = (add ? dst[dst_idx[6] * dst_stridea] : 0) + 0.707106769F * (x10 + x14);
    dst[dst_idx[7] * dst_stridea] = (add ? dst[dst_idx[7] * dst_stridea] : 0) + 0.25F * (x09 + x0b) - 0.353553385F * x0a;
    dst += dst_strideb;
    src += src_strideb;
}
}
