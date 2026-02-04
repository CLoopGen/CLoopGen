#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ptrdiff_t yuv_stride[3];
extern int w;
extern int h;
extern  uint16_t *yuv1;
extern  uint16_t *yuv2;
extern int y;
extern int x;
extern  int uv_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 4) {
        int y00, y01, y02, y03;
        int u0 = yuv1[x+0] - uv_offset, v0 = yuv2[x+0] - uv_offset;
        int u1 = yuv1[x+1] - uv_offset, v1 = yuv2[x+1] - uv_offset;
        int u2 = yuv1[x+2] - uv_offset, v2 = yuv2[x+2] - uv_offset;
        int u3 = yuv1[x+3] - uv_offset, v3 = yuv2[x+3] - uv_offset;
        y00 = u0 * v0;
        y01 = u1 * v1;
        y02 = u2 * v2;
        y03 = u3 * v3;
    }
    yuv1 += yuv_stride[1] / sizeof(uint16_t);
    yuv2 += yuv_stride[2] / sizeof(uint16_t);
}
}
