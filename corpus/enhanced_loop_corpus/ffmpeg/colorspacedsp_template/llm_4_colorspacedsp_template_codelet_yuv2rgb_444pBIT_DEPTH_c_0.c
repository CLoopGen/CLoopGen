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
    for (x = 0; x < w; x++) {
        int u = yuv1[x] - uv_offset;
        int v = yuv2[x] - uv_offset;
        int y00 = u + v;
        if (y00 < 0) {
            y00 = 0;
        }
    }
    yuv1 += yuv_stride[1] / sizeof(uint16_t);
    yuv2 += yuv_stride[2] / sizeof(uint16_t);
}
}
