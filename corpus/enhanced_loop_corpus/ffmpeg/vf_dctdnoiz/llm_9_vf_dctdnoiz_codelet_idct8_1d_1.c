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
for (i = 0; i < 16; i += 2) {
    const float x00_0 = 1.41421354F * src[0 * src_stridea];
    const float x01_0 = 1.3870399F * src[1 * src_stridea] + 0.27589938F * src[7 * src_stridea];
    const float x02_0 = 1.30656302F * src[2 * src_stridea] + 0.541196108F * src[6 * src_stridea];
    const float x03_0 = 1.17587554F * src[3 * src_stridea] + 0.785694956F * src[5 * src_stridea];
    const float x04_0 = 1.41421354F * src[4 * src_stridea];
    const float x05_0 = -0.785694956F * src[3 * src_stridea] + 1.17587554F * src[5 * src_stridea];
    const float x06_0 = 0.541196108F * src[2 * src_stridea] - 1.30656302F * src[6 * src_stridea];
    const float x07_0 = -0.27589938F * src[1 * src_stridea] + 1.3870399F * src[7 * src_stridea];
    const float x09_0 = x00_0 + x04_0;
    const float x0a_0 = x01_0 + x03_0;
    const float x0b_0 = 1.41421354F * x02_0;
    const float x0c_0 = x00_0 - x04_0;
    const float x0d_0 = x01_0 - x03_0;
    const float x0e_0 = 0.353553385F * (x09_0 - x0b_0);
    const float x0f_0 = 0.353553385F * (x0c_0 + x0d_0);
    const float x10_0 = 0.353553385F * (x0c_0 - x0d_0);
    const float x11_0 = 1.41421354F * x06_0;
    const float x12_0 = x05_0 + x07_0;
    const float x13_0 = x05_0 - x07_0;
    const float x14_0 = 0.353553385F * (x11_0 + x12_0);
    const float x15_0 = 0.353553385F * (x11_0 - x12_0);
    const float x16_0 = 0.5F * x13_0;

    // Second iteration unrolled: process next block without advancing src/dst yet
    const float x00_1 = 1.41421354F * src[src_strideb + 0 * src_stridea];
    const float x01_1 = 1.3870399F * src[src_strideb + 1 * src_stridea] + 0.27589938F * src[src_strideb + 7 * src_stridea];
    const float x02_1 = 1.30656302F * src[src_strideb + 2 * src_stridea] + 0.541196108F * src[src_strideb + 6 * src_stridea];
    const float x03_1 = 1.17587554F * src[src_strideb + 3 * src_stridea] + 0.785694956F * src[src_strideb + 5 * src_stridea];
    const float x04_1 = 1.41421354F * src[src_strideb + 4 * src_stridea];
    const float x05_1 = -0.785694956F * src[src_strideb + 3 * src_stridea] + 1.17587554F * src[src_strideb + 5 * src_stridea];
    const float x06_1 = 0.541196108F * src[src_strideb + 2 * src_stridea] - 1.30656302F * src[src_strideb + 6 * src_stridea];
    const float x07_1 = -0.27589938F * src[src_strideb + 1 * src_stridea] + 1.3870399F * src[src_strideb + 7 * src_stridea];
    const float x09_1 = x00_1 + x04_1;
    const float x0a_1 = x01_1 + x03_1;
    const float x0b_1 = 1.41421354F * x02_1;
    const float x0c_1 = x00_1 - x04_1;
    const float x0d_1 = x01_1 - x03_1;
    const float x0e_1 = 0.353553385F * (x09_1 - x0b_1);
    const float x0f_1 = 0.353553385F * (x0c_1 + x0d_1);
    const float x10_1 = 0.353553385F * (x0c_1 - x0d_1);
    const float x11_1 = 1.41421354F * x06_1;
    const float x12_1 = x05_1 + x07_1;
    const float x13_1 = x05_1 - x07_1;
    const float x14_1 = 0.353553385F * (x11_1 + x12_1);
    const float x15_1 = 0.353553385F * (x11_1 - x12_1);
    const float x16_1 = 0.5F * x13_1;

    // Store first result set
    dst[0 * dst_stridea] = (add ? dst[0 * dst_stridea] : 0) + 0.25F * (x09_0 + x0b_0) + 0.353553385F * x0a_0;
    dst[1 * dst_stridea] = (add ? dst[1 * dst_stridea] : 0) + 0.707106769F * (x0f_0 + x15_0);
    dst[2 * dst_stridea] = (add ? dst[2 * dst_stridea] : 0) + 0.707106769F * (x0f_0 - x15_0);
    dst[3 * dst_stridea] = (add ? dst[3 * dst_stridea] : 0) + 0.707106769F * (x0e_0 + x16_0);
    dst[4 * dst_stridea] = (add ? dst[4 * dst_stridea] : 0) + 0.707106769F * (x0e_0 - x16_0);
    dst[5 * dst_stridea] = (add ? dst[5 * dst_stridea] : 0) + 0.707106769F * (x10_0 - x14_0);
    dst[6 * dst_stridea] = (add ? dst[6 * dst_stridea] : 0) + 0.707106769F * (x10_0 + x14_0);
    dst[7 * dst_stridea] = (add ? dst[7 * dst_stridea] : 0) + 0.25F * (x09_0 + x0b_0) - 0.353553385F * x0a_0;

    // Advance to next destination row and store second result
    float* dst_next = dst + dst_strideb;
    dst_next[0 * dst_stridea] = (add ? dst_next[0 * dst_stridea] : 0) + 0.25F * (x09_1 + x0b_1) + 0.353553385F * x0a_1;
    dst_next[1 * dst_stridea] = (add ? dst_next[1 * dst_stridea] : 0) + 0.707106769F * (x0f_1 + x15_1);
    dst_next[2 * dst_stridea] = (add ? dst_next[2 * dst_stridea] : 0) + 0.707106769F * (x0f_1 - x15_1);
    dst_next[3 * dst_stridea] = (add ? dst_next[3 * dst_stridea] : 0) + 0.707106769F * (x0e_1 + x16_1);
    dst_next[4 * dst_stridea] = (add ? dst_next[4 * dst_stridea] : 0) + 0.707106769F * (x0e_1 - x16_1);
    dst_next[5 * dst_stridea] = (add ? dst_next[5 * dst_stridea] : 0) + 0.707106769F * (x10_1 - x14_1);
    dst_next[6 * dst_stridea] = (add ? dst_next[6 * dst_stridea] : 0) + 0.707106769F * (x10_1 + x14_1);
    dst_next[7 * dst_stridea] = (add ? dst_next[7 * dst_stridea] : 0) + 0.25F * (x09_1 + x0b_1) - 0.353553385F * x0a_1;

    dst += 2 * dst_strideb;
    src += 2 * src_strideb;
}
}
