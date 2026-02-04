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
for (i = 0; i < 16; i++) {
    const int src_idx = i * src_strideb;
    const int dst_idx = i * dst_strideb;
    const float *s = &src[src_idx];
    float *d = &dst[dst_idx];

    const float x00 = 1.41421354F * s[0 * src_stridea];
    const float x01 = 1.40740371F * s[1 * src_stridea] + 0.138617173F * s[15 * src_stridea];
    const float x02 = 1.3870399F * s[2 * src_stridea] + 0.27589938F * s[14 * src_stridea];
    const float x03 = 1.35331798F * s[3 * src_stridea] + 0.410524517F * s[13 * src_stridea];
    const float x04 = 1.30656302F * s[4 * src_stridea] + 0.541196108F * s[12 * src_stridea];
    const float x05 = 1.24722505F * s[5 * src_stridea] + 0.66665566F * s[11 * src_stridea];
    const float x06 = 1.17587554F * s[6 * src_stridea] + 0.785694956F * s[10 * src_stridea];
    const float x07 = 1.09320188F * s[7 * src_stridea] + 0.897167563F * s[9 * src_stridea];
    const float x08 = 1.41421354F * s[8 * src_stridea];
    const float x09 = -0.897167563F * s[7 * src_stridea] + 1.09320188F * s[9 * src_stridea];
    const float x0a = 0.785694956F * s[6 * src_stridea] - 1.17587554F * s[10 * src_stridea];
    const float x0b = -0.66665566F * s[5 * src_stridea] + 1.24722505F * s[11 * src_stridea];
    const float x0c = 0.541196108F * s[4 * src_stridea] - 1.30656302F * s[12 * src_stridea];
    const float x0d = -0.410524517F * s[3 * src_stridea] + 1.35331798F * s[13 * src_stridea];
    const float x0e = 0.27589938F * s[2 * src_stridea] - 1.3870399F * s[14 * src_stridea];
    const float x0f = -0.138617173F * s[1 * src_stridea] + 1.40740371F * s[15 * src_stridea];
    const float x12 = x00 + x08;
    const float x13 = x01 + x07;
    const float x14 = x02 + x06;
    const float x15 = x03 + x05;
    const float x16 = 1.41421354F * x04;
    const float x17 = x00 - x08;
    const float x18 = x01 - x07;
    const float x19 = x02 - x06;
    const float x1a = x03 - x05;
    const float x1d = x12 + x16;
    const float x1e = x13 + x15;
    const float x1f = 1.41421354F * x14;
    const float x20 = x12 - x16;
    const float x21 = x13 - x15;
    const float x22 = 0.25F * (x1d - x1f);
    const float x23 = 0.25F * (x20 + x21);
    const float x24 = 0.25F * (x20 - x21);
    const float x25 = 1.41421354F * x17;
    const float x26 = 1.30656302F * x18 + 0.541196108F * x1a;
    const float x27 = 1.41421354F * x19;
    const float x28 = -0.541196108F * x18 + 1.30656302F * x1a;
    const float x29 = 0.176776692F * (x25 + x27) + 0.25F * x26;
    const float x2a = 0.25F * (x25 - x27);
    const float x2b = 0.176776692F * (x25 + x27) - 0.25F * x26;
    const float x2c = 0.353553385F * x28;
    const float x1b = 0.707106769F * (x2a - x2c);
    const float x1c = 0.707106769F * (x2a + x2c);
    const float x2d = 1.41421354F * x0c;
    const float x2e = x0b + x0d;
    const float x2f = x0a + x0e;
    const float x30 = x09 + x0f;
    const float x31 = x09 - x0f;
    const float x32 = x0a - x0e;
    const float x33 = x0b - x0d;
    const float x37 = 1.41421354F * x2d;
    const float x38 = 1.30656302F * x2e + 0.541196108F * x30;
    const float x39 = 1.41421354F * x2f;
    const float x3a = -0.541196108F * x2e + 1.30656302F * x30;
    const float x3b = 0.176776692F * (x37 + x39) + 0.25F * x38;
    const float x3c = 0.25F * (x37 - x39);
    const float x3d = 0.176776692F * (x37 + x39) - 0.25F * x38;
    const float x3e = 0.353553385F * x3a;
    const float x34 = 0.707106769F * (x3c - x3e);
    const float x35 = 0.707106769F * (x3c + x3e);
    const float x3f = 1.41421354F * x32;
    const float x40 = x31 + x33;
    const float x41 = x31 - x33;
    const float x42 = 0.25F * (x3f + x40);
    const float x43 = 0.25F * (x3f - x40);
    const float x44 = 0.353553385F * x41;

    d[0 * dst_stridea] = (add ? d[0 * dst_stridea] : 0) + 0.176776692F * (x1d + x1f) + 0.25F * x1e;
    d[1 * dst_stridea] = (add ? d[1 * dst_stridea] : 0) + 0.707106769F * (x29 + x3d);
    d[2 * dst_stridea] = (add ? d[2 * dst_stridea] : 0) + 0.707106769F * (x29 - x3d);
    d[3 * dst_stridea] = (add ? d[3 * dst_stridea] : 0) + 0.707106769F * (x23 - x43);
    d[4 * dst_stridea] = (add ? d[4 * dst_stridea] : 0) + 0.707106769F * (x23 + x43);
    d[5 * dst_stridea] = (add ? d[5 * dst_stridea] : 0) + 0.707106769F * (x1b - x35);
    d[6 * dst_stridea] = (add ? d[6 * dst_stridea] : 0) + 0.707106769F * (x1b + x35);
    d[7 * dst_stridea] = (add ? d[7 * dst_stridea] : 0) + 0.707106769F * (x22 + x44);
    d[8 * dst_stridea] = (add ? d[8 * dst_stridea] : 0) + 0.707106769F * (x22 - x44);
    d[9 * dst_stridea] = (add ? d[9 * dst_stridea] : 0) + 0.707106769F * (x1c + x34);
    d[10 * dst_stridea] = (add ? d[10 * dst_stridea] : 0) + 0.707106769F * (x1c - x34);
    d[11 * dst_stridea] = (add ? d[11 * dst_stridea] : 0) + 0.707106769F * (x24 + x42);
    d[12 * dst_stridea] = (add ? d[12 * dst_stridea] : 0) + 0.707106769F * (x24 - x42);
    d[13 * dst_stridea] = (add ? d[13 * dst_stridea] : 0) + 0.707106769F * (x2b - x3b);
    d[14 * dst_stridea] = (add ? d[14 * dst_stridea] : 0) + 0.707106769F * (x2b + x3b);
    d[15 * dst_stridea] = (add ? d[15 * dst_stridea] : 0) + 0.176776692F * (x1d + x1f) - 0.25F * x1e;
}
}
