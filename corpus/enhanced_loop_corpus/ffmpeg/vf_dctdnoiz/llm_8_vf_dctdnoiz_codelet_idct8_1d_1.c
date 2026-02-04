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
for (i = 0; i < 4; i++) {
    const float x00 = 1.41421354F * src[0 * src_stridea];
    const float x02 = 1.30656302F * src[2 * src_stridea] + 0.541196108F * src[6 * src_stridea];
    const float x04 = 1.41421354F * src[4 * src_stridea];
    const float x06 = 0.541196108F * src[2 * src_stridea] - 1.30656302F * src[6 * src_stridea];
    const float x09 = x00 + x04;
    const float x0b = 1.41421354F * x02;
    const float x0c = x00 - x04;
    const float x0e = 0.353553385F * (x09 - x0b);
    const float x0f = 0.353553385F * x0c;
    const float x10 = x0c;
    const float x11 = 1.41421354F * x06;
    const float x14 = 0.353553385F * x11;
    const float x16 = 0.0F;
    dst[0 * dst_stridea] = (add ? dst[0 * dst_stridea] : 0) + 0.25F * (x09 + x0b);
    dst[1 * dst_stridea] = (add ? dst[1 * dst_stridea] : 0) + 0.707106769F * x0f;
    dst[2 * dst_stridea] = (add ? dst[2 * dst_stridea] : 0) + 0.707106769F * x0f;
    dst[3 * dst_stridea] = (add ? dst[3 * dst_stridea] : 0) + 0.707106769F * x0e;
    dst[4 * dst_stridea] = (add ? dst[4 * dst_stridea] : 0) + 0.707106769F * x0e;
    dst[5 * dst_stridea] = (add ? dst[5 * dst_stridea] : 0) + 0.707106769F * (x10 - x14);
    dst[6 * dst_stridea] = (add ? dst[6 * dst_stridea] : 0) + 0.707106769F * (x10 + x14);
    dst[7 * dst_stridea] = (add ? dst[7 * dst_stridea] : 0) + 0.25F * (x09 + x0b);
    dst += dst_strideb;
    src += src_strideb;
}
}
