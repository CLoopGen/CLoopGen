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
    for (x = 0; x < b_w; x++) {
        int v = 0;
        for (int i = 0; i < 4; i++) {
            int weight = (i == 0) ? obmc4[x] : 
                         (i == 1) ? obmc3[x] : 
                         (i == 2) ? obmc2[x] : obmc1[x];
            int pixel = block[3-i][x + y * src_stride];
            v += weight * pixel;
        }
        v <<= 8 - 8;
        if (4 != 8) {
            v >>= 8 - 4;
        }
        if (add) {
            int sum = v + dst[x + y * dst_stride];
            int rounded = (sum + (1 << (4 - 1))) >> 4;
            int clamped = (rounded > 255) ? 255 : ((rounded < 0) ? 0 : rounded);
            dst8[x + y * src_stride] = (uint8_t)clamped;
        } else {
            dst[x + y * dst_stride] = dst[x + y * dst_stride] - v;
        }
    }
}
}
