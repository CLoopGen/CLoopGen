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
    const int src_idx = i * src_strideb;
    const int dst_idx = i * dst_strideb;
    const float x00 = src[src_idx + 0 * src_stridea] + src[src_idx + 7 * src_stridea];
    const float x01 = src[src_idx + 1 * src_stridea] + src[src_idx + 6 * src_stridea];
    const float x02 = src[src_idx + 2 * src_stridea] + src[src_idx + 5 * src_stridea];
    const float x03 = src[src_idx + 3 * src_stridea] + src[src_idx + 4 * src_stridea];
    const float x04 = src[src_idx + 0 * src_stridea] - src[src_idx + 7 * src_stridea];
    const float x05 = src[src_idx + 1 * src_stridea] - src[src_idx + 6 * src_stridea];
    const float x06 = src[src_idx + 2 * src_stridea] - src[src_idx + 5 * src_stridea];
    const float x07 = src[src_idx + 3 * src_stridea] - src[src_idx + 4 * src_stridea];
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
    dst[dst_idx + 0 * dst_stridea] = 0.353553385F * (x08 + x09);
    dst[dst_idx + 1 * dst_stridea] = 0.353553385F * (x0c + x0d);
    dst[dst_idx + 2 * dst_stridea] = 0.461939752F * x0a + 0.191341713F * x0b;
    dst[dst_idx + 3 * dst_stridea] = 0.707106769F * (x10 - x11);
    dst[dst_idx + 4 * dst_stridea] = 0.353553385F * (x08 - x09);
    dst[dst_idx + 5 * dst_stridea] = 0.707106769F * (x10 + x11);
    dst[dst_idx + 6 * dst_stridea] = 0.191341713F * x0a - 0.461939752F * x0b;
    dst[dst_idx + 7 * dst_stridea] = 0.353553385F * (x0e + x0f);
}
}
