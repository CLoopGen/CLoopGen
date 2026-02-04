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
for (i = 0; i < 16; i++) {
    const float x00 = src[0 * src_stridea] + src[15 * src_stridea];
    const float x01 = src[1 * src_stridea] + src[14 * src_stridea];
    const float x02 = src[2 * src_stridea] + src[13 * src_stridea];
    const float x03 = src[3 * src_stridea] + src[12 * src_stridea];
    const float x04 = src[4 * src_stridea] + src[11 * src_stridea];
    const float x05 = src[5 * src_stridea] + src[10 * src_stridea];
    const float x06 = src[6 * src_stridea] + src[9 * src_stridea];
    const float x07 = src[7 * src_stridea] + src[8 * src_stridea];

    if (i >= 8) {
        const float x08 = src[0 * src_stridea] - src[15 * src_stridea];
        const float x09 = src[1 * src_stridea] - src[14 * src_stridea];
        const float x0a = src[2 * src_stridea] - src[13 * src_stridea];
        const float x0b = src[3 * src_stridea] - src[12 * src_stridea];
        const float x0c = src[4 * src_stridea] - src[11 * src_stridea];
        const float x0d = src[5 * src_stridea] - src[10 * src_stridea];
        const float x0e = src[6 * src_stridea] - src[9 * src_stridea];
        const float x0f = src[7 * src_stridea] - src[8 * src_stridea];

        const float x10 = x00 + x07;
        const float x11 = x01 + x06;
        const float x12 = x02 + x05;
        const float x13 = x03 + x04;
        const float x14 = x00 - x07;
        const float x15 = x01 - x06;
        const float x16 = x02 - x05;
        const float x17 = x03 - x04;
        const float x18 = x10 + x13;
        const float x19 = x11 + x12;
        const float x1a = x10 - x13;
        const float x1b = x11 - x12;
        const float x1c = 1.3870399F * x14 + 0.27589938F * x17;
        const float x1d = 1.17587554F * x15 + 0.785694956F * x16;
        const float x1e = -0.785694956F * x15 + 1.17587554F * x16;
        const float x1f = 0.27589938F * x14 - 1.3870399F * x17;
        const float x20 = 0.25F * (x1c - x1d);
        const float x21 = 0.25F * (x1e - x1f);

        dst[0 * dst_stridea] = 0.25F * (x18 + x19);
        dst[1 * dst_stridea] = 0.25F * (x1c + x1d);
        dst[2 * dst_stridea] = 0.326640755F * x1a + 0.135299027F * x1b;
        dst[3 * dst_stridea] = 0.707106769F * (x20 - x21);
        dst[4 * dst_stridea] = 0.25F * (x18 - x19);
        dst[5 * dst_stridea] = 0.707106769F * (x20 + x21);
        dst[6 * dst_stridea] = 0.135299027F * x1a - 0.326640755F * x1b;
        dst[7 * dst_stridea] = 0.25F * (x1e + x1f);
    } else {
        const float x10 = x00 + x07;
        const float x11 = x01 + x06;
        const float x12 = x02 + x05;
        const float x13 = x03 + x04;
        const float x18 = x10 + x13;
        const float x19 = x11 + x12;
        const float x1a = x10 - x13;
        const float x1b = x11 - x12;

        dst[0 * dst_stridea] = 0.25F * (x18 + x19);
        dst[1 * dst_stridea] = 0.326640755F * x1a + 0.135299027F * x1b;
        dst[2 * dst_stridea] = 0.25F * (x18 - x19);
        dst[3 * dst_stridea] = 0.135299027F * x1a - 0.326640755F * x1b;

        for (int k = 4; k < 8; k++) {
            dst[k * dst_stridea] = 0.0F;
        }
    }

    dst += dst_strideb;
    src += src_strideb;
}
}
