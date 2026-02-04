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
for (y = 0; y < b_h; y += 2) {
    for (x = 0; x < b_w; x++) {
        const uint8_t *obmc1 = obmc + y * obmc_stride;
        const uint8_t *obmc2 = obmc1 + (obmc_stride >> 1);
        const uint8_t *obmc3 = obmc1 + obmc_stride * (obmc_stride >> 1);
        const uint8_t *obmc4 = obmc3 + (obmc_stride >> 1);

        int v_top = obmc1[x] * block[3][x + y * src_stride] +
                    obmc2[x] * block[2][x + y * src_stride] +
                    obmc3[x] * block[1][x + y * src_stride] +
                    obmc4[x] * block[0][x + y * src_stride];
        v_top <<= 0;
        if (4 != 8) v_top >>= 4;

        int v_bot = 0;
        if (y + 1 < b_h) {
            const uint8_t *obmc1b = obmc + (y+1) * obmc_stride;
            const uint8_t *obmc2b = obmc1b + (obmc_stride >> 1);
            const uint8_t *obmc3b = obmc1b + obmc_stride * (obmc_stride >> 1);
            const uint8_t *obmc4b = obmc3b + (obmc_stride >> 1);

            v_bot = obmc1b[x] * block[3][x + (y+1) * src_stride] +
                    obmc2b[x] * block[2][x + (y+1) * src_stride] +
                    obmc3b[x] * block[1][x + (y+1) * src_stride] +
                    obmc4b[x] * block[0][x + (y+1) * src_stride];
            v_bot <<= 0;
            if (4 != 8) v_bot >>= 4;
        }

        if (add) {
            int val_top = v_top + dst[x + y * dst_stride];
            val_top = (val_top + 8) >> 4;
            if (val_top & ~255) val_top = ~(val_top >> 31);
            dst8[x + y * src_stride] = val_top;

            if (y + 1 < b_h) {
                int val_bot = v_bot + dst[x + (y+1) * dst_stride];
                val_bot = (val_bot + 8) >> 4;
                if (val_bot & ~255) val_bot = ~(val_bot >> 31);
                dst8[x + (y+1) * src_stride] = val_bot;
            }
        } else {
            dst[x + y * dst_stride] -= v_top;
            if (y + 1 < b_h) {
                dst[x + (y+1) * dst_stride] -= v_bot;
            }
        }
    }
}
}
