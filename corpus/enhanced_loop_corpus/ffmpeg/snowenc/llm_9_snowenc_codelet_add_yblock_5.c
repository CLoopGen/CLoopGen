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
for (y = 0; y < (b_h >> 1); y++) {
    const uint8_t *obmc1 = obmc + (y << 1) * obmc_stride;
    const uint8_t *obmc2 = obmc1 + (obmc_stride >> 1);
    const uint8_t *obmc3 = obmc1 + obmc_stride * (obmc_stride >> 1);
    const uint8_t *obmc4 = obmc3 + (obmc_stride >> 1);
    const uint8_t *obmc1b = obmc1 + obmc_stride;
    const uint8_t *obmc2b = obmc2 + obmc_stride;
    const uint8_t *obmc3b = obmc3 + obmc_stride;
    const uint8_t *obmc4b = obmc4 + obmc_stride;
    for (x = 0; x < (b_w >> 1); x++) {
        int val_top_left = obmc1[x] * block[3][x + (y<<1) * src_stride] +
                           obmc2[x] * block[2][x + (y<<1) * src_stride] +
                           obmc3[x] * block[1][x + (y<<1) * src_stride] +
                           obmc4[x] * block[0][x + (y<<1) * src_stride];

        int val_top_right = obmc1[x+1] * block[3][x+1 + (y<<1) * src_stride] +
                            obmc2[x+1] * block[2][x+1 + (y<<1) * src_stride] +
                            obmc3[x+1] * block[1][x+1 + (y<<1) * src_stride] +
                            obmc4[x+1] * block[0][x+1 + (y<<1) * src_stride];

        int val_bot_left = obmc1b[x] * block[3][x + ((y<<1)+1) * src_stride] +
                           obmc2b[x] * block[2][x + ((y<<1)+1) * src_stride] +
                           obmc3b[x] * block[1][x + ((y<<1)+1) * src_stride] +
                           obmc4b[x] * block[0][x + ((y<<1)+1) * src_stride];

        int val_bot_right = obmc1b[x+1] * block[3][x+1 + ((y<<1)+1) * src_stride] +
                            obmc2b[x+1] * block[2][x+1 + ((y<<1)+1) * src_stride] +
                            obmc3b[x+1] * block[1][x+1 + ((y<<1)+1) * src_stride] +
                            obmc4b[x+1] * block[0][x+1 + ((y<<1)+1) * src_stride];

        val_top_left <<= 8;
        val_top_right <<= 8;
        val_bot_left <<= 8;
        val_bot_right <<= 8;

        val_top_left >>= 8 - 4;
        val_top_right >>= 8 - 4;
        val_bot_left >>= 8 - 4;
        val_bot_right >>= 8 - 4;

        if (add) {
            val_top_left += dst[x + (y<<1) * dst_stride];
            val_top_left = (val_top_left + (1 << (4 - 1))) >> 4;
            if (val_top_left & (~255)) val_top_left = ~(val_top_left >> 31);
            dst8[x + (y<<1) * src_stride] = val_top_left;

            val_top_right += dst[x+1 + (y<<1) * dst_stride];
            val_top_right = (val_top_right + (1 << (4 - 1))) >> 4;
            if (val_top_right & (~255)) val_top_right = ~(val_top_right >> 31);
            dst8[x+1 + (y<<1) * src_stride] = val_top_right;

            val_bot_left += dst[x + ((y<<1)+1) * dst_stride];
            val_bot_left = (val_bot_left + (1 << (4 - 1))) >> 4;
            if (val_bot_left & (~255)) val_bot_left = ~(val_bot_left >> 31);
            dst8[x + ((y<<1)+1) * src_stride] = val_bot_left;

            val_bot_right += dst[x+1 + ((y<<1)+1) * dst_stride];
            val_bot_right = (val_bot_right + (1 << (4 - 1))) >> 4;
            if (val_bot_right & (~255)) val_bot_right = ~(val_bot_right >> 31);
            dst8[x+1 + ((y<<1)+1) * src_stride] = val_bot_right;
        } else {
            dst[x + (y<<1) * dst_stride] -= val_top_left;
            dst[x+1 + (y<<1) * dst_stride] -= val_top_right;
            dst[x + ((y<<1)+1) * dst_stride] -= val_bot_left;
            dst[x+1 + ((y<<1)+1) * dst_stride] -= val_bot_right;
        }
    }
}
}
