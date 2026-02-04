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
    const float *src_base = &src[i * src_strideb];
    float *dst_base = &dst[i * dst_strideb];
    const float x00 = src_base[0] + src_base[15 * src_stridea];
    const float x01 = src_base[1 * src_stridea] + src_base[14 * src_stridea];
    const float x02 = src_base[2 * src_stridea] + src_base[13 * src_stridea];
    const float x03 = src_base[3 * src_stridea] + src_base[12 * src_stridea];
    const float x04 = src_base[4 * src_stridea] + src_base[11 * src_stridea];
    const float x05 = src_base[5 * src_stridea] + src_base[10 * src_stridea];
    const float x06 = src_base[6 * src_stridea] + src_base[9 * src_stridea];
    const float x07 = src_base[7 * src_stridea] + src_base[8 * src_stridea];
    const float x08 = src_base[0] - src_base[15 * src_stridea];
    const float x09 = src_base[1 * src_stridea] - src_base[14 * src_stridea];
    const float x0a = src_base[2 * src_stridea] - src_base[13 * src_stridea];
    const float x0b = src_base[3 * src_stridea] - src_base[12 * src_stridea];
    const float x0c = src_base[4 * src_stridea] - src_base[11 * src_stridea];
    const float x0d = src_base[5 * src_stridea] - src_base[10 * src_stridea];
    const float x0e = src_base[6 * src_stridea] - src_base[9 * src_stridea];
    const float x0f = src_base[7 * src_stridea] - src_base[8 * src_stridea];
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
    const float x22 = 1.40740371F * x08 + 0.138617173F * x0f;
    const float x23 = 1.35331798F * x09 + 0.410524517F * x0e;
    const float x24 = 1.24722505F * x0a + 0.66665566F * x0d;
    const float x25 = 1.09320188F * x0b + 0.897167563F * x0c;
    const float x26 = -0.897167563F * x0b + 1.09320188F * x0c;
    const float x27 = 0.66665566F * x0a - 1.24722505F * x0d;
    const float x28 = -0.410524517F * x09 + 1.35331798F * x0e;
    const float x29 = 0.138617173F * x08 - 1.40740371F * x0f;
    const float x2a = x22 + x25;
    const float x2b = x23 + x24;
    const float x2c = x22 - x25;
    const float x2d = x23 - x24;
    const float x2e = 0.25F * (x2a - x2b);
    const float x2f = 0.326640755F * x2c + 0.135299027F * x2d;
    const float x30 = 0.135299027F * x2c - 0.326640755F * x2d;
    const float x31 = x26 + x29;
    const float x32 = x27 + x28;
    const float x33 = x26 - x29;
    const float x34 = x27 - x28;
    const float x35 = 0.25F * (x31 - x32);
    const float x36 = 0.326640755F * x33 + 0.135299027F * x34;
    const float x37 = 0.135299027F * x33 - 0.326640755F * x34;
    dst_base[0] = 0.25F * (x18 + x19);
    dst_base[dst_stridea] = 0.25F * (x2a + x2b);
    dst_base[2 * dst_stridea] = 0.25F * (x1c + x1d);
    dst_base[3 * dst_stridea] = 0.707106769F * (x2f - x37);
    dst_base[4 * dst_stridea] = 0.326640755F * x1a + 0.135299027F * x1b;
    dst_base[5 * dst_stridea] = 0.707106769F * (x2f + x37);
    dst_base[6 * dst_stridea] = 0.707106769F * (x20 - x21);
    dst_base[7 * dst_stridea] = 0.707106769F * (x2e + x35);
    dst_base[8 * dst_stridea] = 0.25F * (x18 - x19);
    dst_base[9 * dst_stridea] = 0.707106769F * (x2e - x35);
    dst_base[10 * dst_stridea] = 0.707106769F * (x20 + x21);
    dst_base[11 * dst_stridea] = 0.707106769F * (x30 - x36);
    dst_base[12 * dst_stridea] = 0.135299027F * x1a - 0.326640755F * x1b;
    dst_base[13 * dst_stridea] = 0.707106769F * (x30 + x36);
    dst_base[14 * dst_stridea] = 0.25F * (x1e + x1f);
    dst_base[15 * dst_stridea] = 0.25F * (x31 + x32);
}
}
