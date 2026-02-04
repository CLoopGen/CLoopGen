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
    for (x = 0; x < b_w; x++) {
        ptrdiff_t offset = y * src_stride + x;
        ptrdiff_t dst_offset = y * dst_stride + x;
        const uint8_t *obmc_base = obmc + (y >> 1) * obmc_stride + (x >> 1);
        int v = obmc_base[0] * block[3][offset] +
                obmc_base[1] * block[2][offset] +
                obmc_base[obmc_stride] * block[1][offset] +
                obmc_base[obmc_stride + 1] * block[0][offset];
        v <<= 0;
        if (4 != 8) {
            v >>= 4;
        }
        if (add) {
            v += dst[dst_offset];
            v = (v + (1 << (4 - 1))) >> 4;
            if (v & (~255))
                v = -(v >> 31) & 255;
            dst8[offset] = v;
        } else {
            dst[dst_offset] -= v;
        }
    }
}
}
