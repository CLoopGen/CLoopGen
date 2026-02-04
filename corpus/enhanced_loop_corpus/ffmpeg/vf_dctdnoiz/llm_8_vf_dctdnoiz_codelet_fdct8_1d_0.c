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
for (i = 0; i < 4; i++) {
    const float x00 = src[0 * src_stridea] + src[7 * src_stridea];
    const float x01 = src[1 * src_stridea] + src[6 * src_stridea];
    const float x02 = src[2 * src_stridea] + src[5 * src_stridea];
    const float x03 = src[3 * src_stridea] + src[4 * src_stridea];
    const float x08 = x00 + x03;
    const float x09 = x01 + x02;
    const float x0a = x00 - x03;
    const float x0b = x01 - x02;
    dst[0 * dst_stridea] = 0.353553385F * (x08 + x09);
    dst[2 * dst_stridea] = 0.461939752F * x0a + 0.191341713F * x0b;
    dst[4 * dst_stridea] = 0.353553385F * (x08 - x09);
    dst[6 * dst_stridea] = 0.191341713F * x0a - 0.461939752F * x0b;
    dst += 2 * dst_strideb;
    src += 2 * src_strideb;
}
}
