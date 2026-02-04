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
for (i = 0; i < 32; i += 2) {
    for (int j = 0; j < 2; ++j) {
        const int idx = j * 8;
        const float x00 = src[(idx+0)*src_stridea] + src[(idx+7)*src_stridea];
        const float x01 = src[(idx+1)*src_stridea] + src[(idx+6)*src_stridea];
        const float x02 = src[(idx+2)*src_stridea] + src[(idx+5)*src_stridea];
        const float x03 = src[(idx+3)*src_stridea] + src[(idx+4)*src_stridea];
        const float x04 = src[(idx+0)*src_stridea] - src[(idx+7)*src_stridea];
        const float x05 = src[(idx+1)*src_stridea] - src[(idx+6)*src_stridea];
        const float x06 = src[(idx+2)*src_stridea] - src[(idx+5)*src_stridea];
        const float x07 = src[(idx+3)*src_stridea] - src[(idx+4)*src_stridea];
        const float x08 = x00 + x03;
        const float x09 = x01 + x02;
        const float x0a = x00 - x03;
        const float x0b = x01 - x02;
        const float x0c = 1.3065629F * x04 + 0.5411961F * x07;
        const float x0d = 0.5411961F * x04 - 1.3065629F * x07;
        const float x0e = 1.3870399F * x0a + 0.27589938F * x0b;
        const float x0f = 1.17587554F * x0a - 0.785694956F * x0b;
        dst[(idx+0)*dst_stridea] = 0.25F * (x08 + x09);
        dst[(idx+1)*dst_stridea] = 0.707106769F * (x0e - x0f);
        dst[(idx+2)*dst_stridea] = 0.25F * (x08 - x09);
        dst[(idx+3)*dst_stridea] = 0.707106769F * (x0e + x0f);
        dst[(idx+4)*dst_stridea] = 0.25F * (x0c - x0d);
        dst[(idx+5)*dst_stridea] = 0.707106769F * (x0e - x0f);
        dst[(idx+6)*dst_stridea] = 0.25F * (x0c + x0d);
        dst[(idx+7)*dst_stridea] = 0.707106769F * (x0e + x0f);
    }
    dst += 2 * dst_strideb;
    src += 2 * src_strideb;
}
}
