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
    const float s0 = src[0 * src_stridea];
    const float s1 = src[1 * src_stridea];
    const float s2 = src[2 * src_stridea];
    const float s3 = src[3 * src_stridea];
    const float s4 = src[4 * src_stridea];
    const float s5 = src[5 * src_stridea];
    const float s6 = src[6 * src_stridea];
    const float s7 = src[7 * src_stridea];

    const float t0 = s0 + s7;
    const float t1 = s1 + s6;
    const float t2 = s2 + s5;
    const float t3 = s3 + s4;
    const float t4 = s0 - s7;
    const float t5 = s1 - s6;
    const float t6 = s2 - s5;
    const float t7 = s3 - s4;

    const float u0 = t0 + t3;
    const float u1 = t1 + t2;
    const float u2 = t0 - t3;
    const float u3 = t1 - t2;

    const float v0 = 1.3870399F * t4 + 0.27589938F * t7;
    const float v1 = 1.17587554F * t5 + 0.785694956F * t6;
    const float v2 = -0.785694956F * t5 + 1.17587554F * t6;
    const float v3 = 0.27589938F * t4 - 1.3870399F * t7;

    const float w0 = 0.353553385F * (v0 - v1);
    const float w1 = 0.353553385F * (v2 - v3);

    dst[0 * dst_stridea] = 0.353553385F * (u0 + u1);
    dst[1 * dst_stridea] = 0.353553385F * (v0 + v1);
    dst[2 * dst_stridea] = 0.461939752F * u2 + 0.191341713F * u3;
    dst[3 * dst_stridea] = 0.707106769F * (w0 - w1);
    dst[4 * dst_stridea] = 0.353553385F * (u0 - u1);
    dst[5 * dst_stridea] = 0.707106769F * (w0 + w1);
    dst[6 * dst_stridea] = 0.191341713F * u2 - 0.461939752F * u3;
    dst[7 * dst_stridea] = 0.353553385F * (v2 + v3);

    // Unrolled update with reduced stride adjustment frequency
    if (i % 2 == 0) {
        dst += dst_strideb;
        src += src_strideb;
    }
}
}
