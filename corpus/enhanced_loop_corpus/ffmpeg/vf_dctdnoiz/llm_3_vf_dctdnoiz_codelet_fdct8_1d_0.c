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
    const int src_offset = i * src_strideb;
    const int dst_offset = i * dst_strideb;
    float temp_src[8];
    float temp_dst[8];

    for (int j = 0; j < 8; j++) {
        temp_src[j] = src[src_offset + j * src_stridea];
    }

    const float x00 = temp_src[0] + temp_src[7];
    const float x01 = temp_src[1] + temp_src[6];
    const float x02 = temp_src[2] + temp_src[5];
    const float x03 = temp_src[3] + temp_src[4];
    const float x04 = temp_src[0] - temp_src[7];
    const float x05 = temp_src[1] - temp_src[6];
    const float x06 = temp_src[2] - temp_src[5];
    const float x07 = temp_src[3] - temp_src[4];
    const float x08 = x00 + x03;
    const float x09 = x01 + x02;
    const float x0a = x00 - x03;
    const float x0b = x01 - x02;
    const float x0c = 1.3870399F * x04 + 0.27589938F * x07;
    const float x0d = 1.17587554F * x05 + 0.785694956F * x06;
    const float x0e = -0.785694956F * x05 + 1.17587554F * x06;
    const float x0f = 0.27589938F * x04 - 1.3870399F * x07;
    const float x10 = 0.353553385F * (x0c - x0d);
    const float x11 = 0.353553385F * (x0e - x0f);

    temp_dst[0] = 0.353553385F * (x08 + x09);
    temp_dst[1] = 0.353553385F * (x0c + x0d);
    temp_dst[2] = 0.461939752F * x0a + 0.191341713F * x0b;
    temp_dst[3] = 0.707106769F * (x10 - x11);
    temp_dst[4] = 0.353553385F * (x08 - x09);
    temp_dst[5] = 0.707106769F * (x10 + x11);
    temp_dst[6] = 0.191341713F * x0a - 0.461939752F * x0b;
    temp_dst[7] = 0.353553385F * (x0e + x0f);

    for (int j = 0; j < 8; j++) {
        dst[dst_offset + j * dst_stridea] = temp_dst[j];
    }
}
}
