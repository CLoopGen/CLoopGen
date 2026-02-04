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
for (i = 0; i < 8; i++) {
    // Reorder computations to eliminate some intermediate dependencies and promote parallelism
    // Load all source values first, then perform independent calculations in groups

    const float s0 = src[0 * src_stridea];
    const float s1 = src[1 * src_stridea];
    const float s2 = src[2 * src_stridea];
    const float s3 = src[3 * src_stridea];
    const float s4 = src[4 * src_stridea];
    const float s5 = src[5 * src_stridea];
    const float s6 = src[6 * src_stridea];
    const float s7 = src[7 * src_stridea];

    // Group independent operations to minimize data dependency chains
    const float t0 = 1.41421354F * s0;
    const float t1 = 1.3870399F * s1;
    const float t2 = 0.27589938F * s7;
    const float t3 = 1.30656302F * s2;
    const float t4 = 0.541196108F * s6;
    const float t5 = 1.17587554F * s3;
    const float t6 = 0.785694956F * s5;
    const float t7 = 1.41421354F * s4;
    const float t8 = -0.785694956F * s3;
    const float t9 = 1.17587554F * s5;
    const float t10 = 0.541196108F * s2;
    const float t11 = -1.30656302F * s6;
    const float t12 = -0.27589938F * s1;
    const float t13 = 1.3870399F * s7;

    // Combine results with minimal sequential dependencies
    const float x00 = t0;
    const float x01 = t1 + t2;
    const float x02 = t3 + t4;
    const float x03 = t5 + t6;
    const float x04 = t7;
    const float x05 = t8 + t9;
    const float x06 = t10 + t11;
    const float x07 = t12 + t13;

    const float x09 = x00 + x04;
    const float x0a = x01 + x03;
    const float x0b = 1.41421354F * x02;
    const float x0c = x00 - x04;
    const float x0d = x01 - x03;
    const float x0e = 0.353553385F * (x09 - x0b);
    const float x0f = 0.353553385F * (x0c + x0d);
    const float x10 = 0.353553385F * (x0c - x0d);
    const float x11 = 1.41421354F * x06;
    const float x12 = x05 + x07;
    const float x13 = x05 - x07;
    const float x14 = 0.353553385F * (x11 + x12);
    const float x15 = 0.353553385F * (x11 - x12);
    const float x16 = 0.5F * x13;

    // Remove conditional data hazard by precomputing base value
    const float base_val = 0.25F * (x09 + x0b);
    const float term_a = 0.353553385F * x0a;

    dst[0 * dst_stridea] = (add ? dst[0 * dst_stridea] : 0) + base_val + term_a;
    dst[1 * dst_stridea] = (add ? dst[1 * dst_stridea] : 0) + 0.707106769F * (x0f + x15);
    dst[2 * dst_stridea] = (add ? dst[2 * dst_stridea] : 0) + 0.707106769F * (x0f - x15);
    dst[3 * dst_stridea] = (add ? dst[3 * dst_stridea] : 0) + 0.707106769F * (x0e + x16);
    dst[4 * dst_stridea] = (add ? dst[4 * dst_stridea] : 0) + 0.707106769F * (x0e - x16);
    dst[5 * dst_stridea] = (add ? dst[5 * dst_stridea] : 0) + 0.707106769F * (x10 - x14);
    dst[6 * dst_stridea] = (add ? dst[6 * dst_stridea] : 0) + 0.707106769F * (x10 + x14);
    dst[7 * dst_stridea] = (add ? dst[7 * dst_stridea] : 0) + base_val - term_a;

    dst += dst_strideb;
    src += src_strideb;
}
}
