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
for (i = 0; i < 32; i++) {
    for (int j = 0; j < 2; ++j) {
        const float s0 = (j == 0) ? src[0 * src_stridea] : src[16 * src_stridea];
        const float s1 = (j == 0) ? src[1 * src_stridea] : src[17 * src_stridea];
        const float s2 = (j == 0) ? src[2 * src_stridea] : src[18 * src_stridea];
        const float s3 = (j == 0) ? src[3 * src_stridea] : src[19 * src_stridea];
        const float s4 = (j == 0) ? src[4 * src_stridea] : src[20 * src_stridea];
        const float s5 = (j == 0) ? src[5 * src_stridea] : src[21 * src_stridea];
        const float s6 = (j == 0) ? src[6 * src_stridea] : src[22 * src_stridea];
        const float s7 = (j == 0) ? src[7 * src_stridea] : src[23 * src_stridea];
        const float s8 = (j == 0) ? src[8 * src_stridea] : src[24 * src_stridea];
        const float s9 = (j == 0) ? src[9 * src_stridea] : src[25 * src_stridea];
        const float s10 = (j == 0) ? src[10 * src_stridea] : src[26 * src_stridea];
        const float s11 = (j == 0) ? src[11 * src_stridea] : src[27 * src_stridea];
        const float s12 = (j == 0) ? src[12 * src_stridea] : src[28 * src_stridea];
        const float s13 = (j == 0) ? src[13 * src_stridea] : src[29 * src_stridea];
        const float s14 = (j == 0) ? src[14 * src_stridea] : src[30 * src_stridea];
        const float s15 = (j == 0) ? src[15 * src_stridea] : src[31 * src_stridea];

        const float x00 = 1.41421354F * s0;
        const float x01 = 1.40740371F * s1 + 0.138617173F * s15;
        const float x02 = 1.3870399F * s2 + 0.27589938F * s14;
        const float x03 = 1.35331798F * s3 + 0.410524517F * s13;
        const float x04 = 1.30656302F * s4 + 0.541196108F * s12;
        const float x05 = 1.24722505F * s5 + 0.66665566F * s11;
        const float x06 = 1.17587554F * s6 + 0.785694956F * s10;
        const float x07 = 1.09320188F * s7 + 0.897167563F * s9;
        const float x08 = 1.41421354F * s8;

        const float x12 = x00 + x08;
        const float x13 = x01 + x07;
        const float x14 = x02 + x06;
        const float x15 = x03 + x05;
        const float x16 = 1.41421354F * x04;
        const float x1d = x12 + x16;
        const float x1e = x13 + x15;
        const float x1f = 1.41421354F * x14;

        const int offset = j * 16;
        dst[offset + 0 * dst_stridea] = (add ? dst[offset + 0 * dst_stridea] : 0) + 0.176776692F * (x1d + x1f) + 0.25F * x1e;
        dst[offset + 1 * dst_stridea] = (add ? dst[offset + 1 * dst_stridea] : 0) + 0.707106769F * (x13 + x15);
        dst[offset + 2 * dst_stridea] = (add ? dst[offset + 2 * dst_stridea] : 0) + 0.707106769F * (x13 - x15);
        dst[offset + 3 * dst_stridea] = (add ? dst[offset + 3 * dst_stridea] : 0) + 0.707106769F * (x12 - x16);
        dst[offset + 4 * dst_stridea] = (add ? dst[offset + 4 * dst_stridea] : 0) + 0.707106769F * (x12 + x16);
        dst[offset + 5 * dst_stridea] = (add ? dst[offset + 5 * dst_stridea] : 0) + 0.707106769F * (x00 - x08);
        dst[offset + 6 * dst_stridea] = (add ? dst[offset + 6 * dst_stridea] : 0) + 0.707106769F * (x01 - x07);
        dst[offset + 7 * dst_stridea] = (add ? dst[offset + 7 * dst_stridea] : 0) + 0.707106769F * (x02 - x06);
    }
    dst += 2 * dst_strideb;
    src += 2 * src_strideb;
}
}
