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
    for (x = 0; x < b_w; x += 2) {
        const int idxs[4] = {x + y * src_stride, x+1 + y * src_stride, x + (y+1) * src_stride, x+1 + (y+1) * src_stride};
        const int obmc_off[4] = {y * obmc_stride + x, y * obmc_stride + x+1,
                                (y + (obmc_stride >> 1)) * obmc_stride + x, (y + (obmc_stride >> 1)) * obmc_stride + x+1};
        for (int py = 0; py < 2 && (y + py) < b_h; py++) {
            for (int px = 0; px < 2 && (x + px) < b_w; px++) {
                int pos = py * 2 + px;
                int i = idxs[pos];
                int v = 0;
                v += obmc[obmc_off[0] + py*(obmc_stride>>1) + px] * block[3][i];
                v += obmc[obmc_off[1] + py*(obmc_stride>>1) + px] * block[2][i];
                v += obmc[obmc_off[2] + py*(obmc_stride>>1) + px] * block[1][i];
                v += obmc[obmc_off[3] + py*(obmc_stride>>1) + px] * block[0][i];
                v <<= 0;
                if (4 != 8) {
                    v >>= 4;
                }
                if (add) {
                    v += dst[i];
                    v = (v + (1 << (4 - 1))) >> 4;
                    if (v & (~255))
                        v = ~(v >> 31);
                    dst8[i] = v;
                } else {
                    dst[i] -= v;
                }
            }
        }
    }
}
}
