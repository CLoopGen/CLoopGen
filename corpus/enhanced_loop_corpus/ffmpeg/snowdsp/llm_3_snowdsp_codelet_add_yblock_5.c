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
        const uint8_t *obmc_rows[4] = {
            obmc + y * obmc_stride,
            obmc + y * obmc_stride + (obmc_stride >> 1),
            obmc + (y + (obmc_stride >> 1)) * obmc_stride,
            obmc + (y + (obmc_stride >> 1)) * obmc_stride + (obmc_stride >> 1)
        };
        int bx = x + y * src_stride;
        int offsets[4] = {bx, bx + 1, bx + src_stride, bx + src_stride + 1};
        for (int p = 0; p < (b_h - y >= 2 ? 4 : (b_h - y) * 2); p++) {
            if (p >= (b_h - y) * (b_w - x)) break;
            int xi = offsets[p] % src_stride - y * src_stride + x;
            int yi = offsets[p] / src_stride;
            if (xi >= x + 2 || yi != y + (p >= 2)) continue;
            int v = obmc_rows[0][xi] * block[3][offsets[p]] +
                    obmc_rows[1][xi] * block[2][offsets[p]] +
                    obmc_rows[2][xi] * block[1][offsets[p]] +
                    obmc_rows[3][xi] * block[0][offsets[p]];
            v <<= 0;
            if (4 != 8) {
                v >>= 4;
            }
            if (add) {
                v += dst[offsets[p]];
                v = (v + (1 << (4 - 1))) >> 4;
                if (v & (~255))
                    v = ~(v >> 31);
                dst8[offsets[p]] = v;
            } else {
                dst[offsets[p]] -= v;
            }
        }
    }
}
}
