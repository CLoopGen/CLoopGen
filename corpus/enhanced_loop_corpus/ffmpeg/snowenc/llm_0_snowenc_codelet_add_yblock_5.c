#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *dst;
extern uint8_t *dst8;
extern  uint8_t *obmc;
extern int b_w;
extern int b_h;
extern int dst_stride;
extern int src_stride;
extern int obmc_stride;
extern int add;
extern uint8_t *block[4];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < b_h; y++) {
    const uint8_t *obmc1 = obmc + y * obmc_stride;
    const uint8_t *obmc2 = obmc1 + (obmc_stride >> 1);
    const uint8_t *obmc3 = obmc1 + obmc_stride * (obmc_stride >> 1);
    const uint8_t *obmc4 = obmc3 + (obmc_stride >> 1);
    int x = 0;
    for (; x < b_w - 3; x += 4) {
        int v0 = obmc1[x+0] * block[3][x+0 + y * src_stride] + obmc2[x+0] * block[2][x+0 + y * src_stride] +
                 obmc3[x+0] * block[1][x+0 + y * src_stride] + obmc4[x+0] * block[0][x+0 + y * src_stride];
        int v1 = obmc1[x+1] * block[3][x+1 + y * src_stride] + obmc2[x+1] * block[2][x+1 + y * src_stride] +
                 obmc3[x+1] * block[1][x+1 + y * src_stride] + obmc4[x+1] * block[0][x+1 + y * src_stride];
        int v2 = obmc1[x+2] * block[3][x+2 + y * src_stride] + obmc2[x+2] * block[2][x+2 + y * src_stride] +
                 obmc3[x+2] * block[1][x+2 + y * src_stride] + obmc4[x+2] * block[0][x+2 + y * src_stride];
        int v3 = obmc1[x+3] * block[3][x+3 + y * src_stride] + obmc2[x+3] * block[2][x+3 + y * src_stride] +
                 obmc3[x+3] * block[1][x+3 + y * src_stride] + obmc4[x+3] * block[0][x+3 + y * src_stride];

        v0 <<= 8 - 8;
        v1 <<= 8 - 8;
        v2 <<= 8 - 8;
        v3 <<= 8 - 8;

        if (4 != 8) {
            v0 >>= 8 - 4;
            v1 >>= 8 - 4;
            v2 >>= 8 - 4;
            v3 >>= 8 - 4;
        }

        if (add) {
            int d0 = dst[x+0 + y * dst_stride];
            int d1 = dst[x+1 + y * dst_stride];
            int d2 = dst[x+2 + y * dst_stride];
            int d3 = dst[x+3 + y * dst_stride];

            v0 = (v0 + d0 + (1 << (4 - 1))) >> 4;
            v1 = (v1 + d1 + (1 << (4 - 1))) >> 4;
            v2 = (v2 + d2 + (1 << (4 - 1))) >> 4;
            v3 = (v3 + d3 + (1 << (4 - 1))) >> 4;

            if (v0 & (~255)) v0 = ~(v0 >> 31);
            if (v1 & (~255)) v1 = ~(v1 >> 31);
            if (v2 & (~255)) v2 = ~(v2 >> 31);
            if (v3 & (~255)) v3 = ~(v3 >> 31);

            dst8[x+0 + y * src_stride] = v0;
            dst8[x+1 + y * src_stride] = v1;
            dst8[x+2 + y * src_stride] = v2;
            dst8[x+3 + y * src_stride] = v3;
        } else {
            dst[x+0 + y * dst_stride] -= v0;
            dst[x+1 + y * dst_stride] -= v1;
            dst[x+2 + y * dst_stride] -= v2;
            dst[x+3 + y * dst_stride] -= v3;
        }
    }
    for (; x < b_w; x++) {
        int v = obmc1[x] * block[3][x + y * src_stride] + obmc2[x] * block[2][x + y * src_stride] +
                obmc3[x] * block[1][x + y * src_stride] + obmc4[x] * block[0][x + y * src_stride];
        v <<= 8 - 8;
        if (4 != 8) {
            v >>= 8 - 4;
        }
        if (add) {
            v += dst[x + y * dst_stride];
            v = (v + (1 << (4 - 1))) >> 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8[x + y * src_stride] = v;
        } else {
            dst[x + y * dst_stride] -= v;
        }
    }
}
}
