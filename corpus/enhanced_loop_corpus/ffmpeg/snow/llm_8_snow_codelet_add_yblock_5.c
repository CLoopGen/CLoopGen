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
    for (x = 0; x < b_w; x += 2) {
        int v1 = obmc1[x] * block[3][x + y * src_stride] + obmc2[x] * block[2][x + y * src_stride];
        int v2 = obmc1[x+1] * block[3][x+1 + y * src_stride] + obmc2[x+1] * block[2][x+1 + y * src_stride];
        v1 <<= 1;
        v2 <<= 1;
        if (add) {
            v1 += dst[x + y * dst_stride];
            v2 += dst[x+1 + y * dst_stride];
            v1 = (v1 + 1) >> 1;
            v2 = (v2 + 1) >> 1;
            if (v1 > 255) v1 = 255;
            else if (v1 < 0) v1 = 0;
            if (v2 > 255) v2 = 255;
            else if (v2 < 0) v2 = 0;
            dst8[x + y * src_stride] = v1;
            dst8[x+1 + y * src_stride] = v2;
        } else {
            dst[x + y * dst_stride] -= v1;
            dst[x+1 + y * dst_stride] -= v2;
        }
    }
}
}
