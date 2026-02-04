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
    const float s0 = src[0 * src_stridea],  s15 = src[15 * src_stridea];
    const float s1 = src[1 * src_stridea],  s14 = src[14 * src_stridea];
    const float s2 = src[2 * src_stridea],  s13 = src[13 * src_stridea];
    const float s3 = src[3 * src_stridea],  s12 = src[12 * src_stridea];
    const float s4 = src[4 * src_stridea],  s11 = src[11 * src_stridea];
    const float s5 = src[5 * src_stridea],  s10 = src[10 * src_stridea];
    const float s6 = src[6 * src_stridea],  s9  = src[9  * src_stridea];
    const float s7 = src[7 * src_stridea],  s8  = src[8  * src_stridea];

    const float x00 = s0 + s15;
    const float x01 = s1 + s14;
    const float x02 = s2 + s13;
    const float x03 = s3 + s12;
    const float x04 = s4 + s11;
    const float x05 = s5 + s10;
    const float x06 = s6 + s9;
    const float x07 = s7 + s8;
    const float x08 = s0 - s15;
    const float x09 = s1 - s14;
    const float x0a = s2 - s13;
    const float x0b = s3 - s12;
    const float x0c = s4 - s11;
    const float x0d = s5 - s10;
    const float x0e = s6 - s9;
    const float x0f = s7 - s8;

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

    const float t1c = 1.3870399F * x14;
    const float t1d = 0.27589938F * x17;
    const float t1e = 1.17587554F * x15;
    const float t1f = 0.785694956F * x16;
    const float x1c = t1c + t1d;
    const float x1d = t1e + t1f;
    const float x1e = -t1f + 1.17587554F * x16;
    const float x1f = t1d - 1.3870399F * x17;

    const float x20 = 0.25F * (x1c - x1d);
    const float x21 = 0.25F * (x1e - x1f);

    const float t22 = 1.40740371F * x08;
    const float t23 = 0.138617173F * x0f;
    const float t24 = 1.35331798F * x09;
    const float t25 = 0.410524517F * x0e;
    const float t26 = 1.24722505F * x0a;
    const float t27 = 0.66665566F * x0d;
    const float t28 = 1.09320188F * x0b;
    const float t29 = 0.897167563F * x0c;

    const float x22 = t22 + t23;
    const float x23 = t24 + t25;
    const float x24 = t26 + t27;
    const float x25 = t28 + t29;
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

    dst[0 * dst_stridea] = 0.25F * (x18 + x19);
    dst[1 * dst_stridea] = 0.25F * (x2a + x2b);
    dst[2 * dst_stridea] = 0.25F * (x1c + x1d);
    dst[3 * dst_stridea] = 0.707106769F * (x2f - x37);
    dst[4 * dst_stridea] = 0.326640755F * x1a + 0.135299027F * x1b;
    dst[5 * dst_stridea] = 0.707106769F * (x2f + x37);
    dst[6 * dst_stridea] = 0.707106769F * (x20 - x21);
    dst[7 * dst_stridea] = 0.707106769F * (x2e + x35);
    dst[8 * dst_stridea] = 0.25F * (x18 - x19);
    dst[9 * dst_stridea] = 0.707106769F * (x2e - x35);
    dst[10 * dst_stridea] = 0.707106769F * (x20 + x21);
    dst[11 * dst_stridea] = 0.707106769F * (x30 - x36);
    dst[12 * dst_stridea] = 0.135299027F * x1a - 0.326640755F * x1b;
    dst[13 * dst_stridea] = 0.707106769F * (x30 + x36);
    dst[14 * dst_stridea] = 0.25F * (x1e + x1f);
    dst[15 * dst_stridea] = 0.25F * (x31 + x32);

    dst += dst_strideb;
    src += src_strideb;
}
}
