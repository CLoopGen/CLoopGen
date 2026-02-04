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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const float x00 = src[0 * src_stridea] + src[7 * src_stridea];
    const float x01 = src[1 * src_stridea] + src[6 * src_stridea];
    const float x02 = src[2 * src_stridea] + src[5 * src_stridea];
    const float x03 = src[3 * src_stridea] + src[4 * src_stridea];
    const float x04 = src[0 * src_stridea] - src[7 * src_stridea];
    const float x05 = src[1 * src_stridea] - src[6 * src_stridea];
    const float x06 = src[2 * src_stridea] - src[5 * src_stridea];
    const float x07 = src[3 * src_stridea] - src[4 * src_stridea];
    const float x08 = x00 + x03;
    const float x09 = x01 + x02;
    const float x0a = x00 - x03;
    const float x0b = x01 - x02;
    const float x0c = 1.3065629F * x04 + 0.5411961F * x07;
    const float x0d = 0.5411961F * x04 - 1.3065629F * x07;
    const float x0e = 1.3870399F * x0a + 0.27589938F * x0b;
    const float x0f = 1.17587554F * x0a - 0.785694956F * x0b;
    dst[0 * dst_stridea] = 0.25F * (x08 + x09);
    dst[1 * dst_stridea] = 0.707106769F * (x0e - x0f);
    dst[2 * dst_stridea] = 0.25F * (x08 - x09);
    dst[3 * dst_stridea] = 0.707106769F * (x0e + x0f);
    dst[4 * dst_stridea] = 0.25F * (x0c - x0d);
    dst[5 * dst_stridea] = 0.707106769F * (x0e - x0f); 
    dst[6 * dst_stridea] = 0.25F * (x0c + x0d);
    dst[7 * dst_stridea] = 0.707106769F * (x0e + x0f);
    dst += dst_strideb;
    src += src_strideb;
}
}
