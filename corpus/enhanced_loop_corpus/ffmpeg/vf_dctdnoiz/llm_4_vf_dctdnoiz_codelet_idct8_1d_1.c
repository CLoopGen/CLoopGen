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
    const float x00 = 1.41421354F * src[0 * src_stridea];
    const float x01 = 1.3870399F * src[1 * src_stridea] + 0.27589938F * src[7 * src_stridea];
    const float x02 = 1.30656302F * src[2 * src_stridea] + 0.541196108F * src[6 * src_stridea];
    const float x03 = 1.17587554F * src[3 * src_stridea] + 0.785694956F * src[5 * src_stridea];
    const float x04 = 1.41421354F * src[4 * src_stridea];
    const float x05 = -0.785694956F * src[3 * src_stridea] + 1.17587554F * src[5 * src_stridea];
    const float x06 = 0.541196108F * src[2 * src_stridea] - 1.30656302F * src[6 * src_stridea];
    const float x07 = -0.27589938F * src[1 * src_stridea] + 1.3870399F * src[7 * src_stridea];
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

    if (add) {
        dst[0 * dst_stridea] += 0.25F * (x09 + x0b) + 0.353553385F * x0a;
        dst[1 * dst_stridea] += 0.707106769F * (x0f + x15);
        dst[2 * dst_stridea] += 0.707106769F * (x0f - x15);
        dst[3 * dst_stridea] += 0.707106769F * (x0e + x16);
        dst[4 * dst_stridea] += 0.707106769F * (x0e - x16);
        dst[5 * dst_stridea] += 0.707106769F * (x10 - x14);
        dst[6 * dst_stridea] += 0.707106769F * (x10 + x14);
        dst[7 * dst_stridea] += 0.25F * (x09 + x0b) - 0.353553385F * x0a;
    } else {
        dst[0 * dst_stridea] = 0.25F * (x09 + x0b) + 0.353553385F * x0a;
        dst[1 * dst_stridea] = 0.707106769F * (x0f + x15);
        dst[2 * dst_stridea] = 0.707106769F * (x0f - x15);
        dst[3 * dst_stridea] = 0.707106769F * (x0e + x16);
        dst[4 * dst_stridea] = 0.707106769F * (x0e - x16);
        dst[5 * dst_stridea] = 0.707106769F * (x10 - x14);
        dst[6 * dst_stridea] = 0.707106769F * (x10 + x14);
        dst[7 * dst_stridea] = 0.25F * (x09 + x0b) - 0.353553385F * x0a;
    }

    dst += dst_strideb;
    src += src_strideb;
}
}
