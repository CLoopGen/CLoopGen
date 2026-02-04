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
    float temp_results[8];

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

    const float x0c = 1.3870399F * x04 + 0.27589938F * x07;
    const float x0d = 1.17587554F * x05 + 0.785694956F * x06;
    const float x0e = -0.785694956F * x05 + 1.17587554F * x06;
    const float x0f = 0.27589938F * x04 - 1.3870399F * x07;

    const float x10 = 0.353553385F * (x0c - x0d);
    const float x11 = 0.353553385F * (x0e - x0f);

    temp_results[0] = 0.353553385F * (x08 + x09);
    temp_results[1] = 0.353553385F * (x0c + x0d);
    temp_results[2] = 0.461939752F * x0a + 0.191341713F * x0b;
    temp_results[3] = 0.707106769F * (x10 - x11);
    temp_results[4] = 0.353553385F * (x08 - x09);
    temp_results[5] = 0.707106769F * (x10 + x11);
    temp_results[6] = 0.191341713F * x0a - 0.461939752F * x0b;
    temp_results[7] = 0.353553385F * (x0e + x0f);

    for (int j = 0; j < 8; j++) {
        dst[j * dst_stridea] = temp_results[j];
    }

    dst += dst_strideb;
    src += src_strideb;
}
}
