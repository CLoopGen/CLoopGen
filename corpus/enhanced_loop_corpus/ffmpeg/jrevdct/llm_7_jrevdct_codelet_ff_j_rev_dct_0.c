#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern int32_t tmp0;
extern int32_t tmp1;
extern int32_t tmp2;
extern int32_t tmp3;
extern int32_t tmp10;
extern int32_t tmp11;
extern int32_t tmp12;
extern int32_t tmp13;
extern int32_t z1;
extern int32_t z2;
extern int32_t z3;
extern int32_t z4;
extern int32_t z5;
extern int32_t d0;
extern int32_t d1;
extern int32_t d2;
extern int32_t d3;
extern int32_t d4;
extern int32_t d5;
extern int32_t d6;
extern int32_t d7;
extern int16_t *dataptr;
extern int rowctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rowctr = 8 - 1; rowctr >= 0; rowctr--) {
    register uint8_t *idataptr = (uint8_t *)dataptr;
    d0 = dataptr[0];
    d1 = dataptr[4];
    d2 = dataptr[1];
    d3 = dataptr[5];
    d4 = dataptr[2];
    d5 = dataptr[6];
    d6 = dataptr[3];
    d7 = dataptr[7];

    if ((d1 | d2 | d3 | d4 | d5 | d6 | d7) == 0 && d0 != 0) {
        int16_t dcval = (int16_t)(d0 * (1 << 2));
        register int v = (dcval & 65535) | ((dcval * (1 << 16)) & 4294901760U);
        (((av_alias32 *)(&idataptr[0]))->u32 = (v));
        (((av_alias32 *)(&idataptr[4]))->u32 = (v));
        (((av_alias32 *)(&idataptr[8]))->u32 = (v));
        (((av_alias32 *)(&idataptr[12]))->u32 = (v));
        dataptr += 8;
        continue;
    }

    int32_t sum_all = d0 + d1 + d2 + d3 + d4 + d5 + d6 + d7;
    int32_t base_shift = (sum_all & 1) ? 13 : 12;  // Loop-carried control dependency via data
    int32_t scale = (1 << base_shift);

    tmp0 = (d0 + d4) * scale;
    tmp1 = (d0 - d4) * scale;

    z1 = (d2 != 0 || d6 != 0) ? ((d2 + d6) * 4433) : 0;
    tmp2 = (d6 != 0) ? (z1 + (-d6 * 15137)) : (d2 ? (d2 * 4433) : 0);
    tmp3 = (d2 != 0) ? (z1 + (d2 * 6270)) : (d6 ? (d6 * 4433) : 0);

    tmp10 = tmp0 + tmp3 + (sum_all & 0x3);  // Artificial WAW+RAW dependency
    tmp13 = tmp0 - tmp3 + (sum_all & 0x3);
    tmp11 = tmp1 + tmp2 + (sum_all & 0x3);
    tmp12 = tmp1 - tmp2 + (sum_all & 0x3);

    z5 = 9633 * ((d1 + d3 + d5 + d7) / 4 + 1);  // Average-based pre-factor
    tmp0 = (d7 * (2446 - 7373)) + (d1 * (12299 - 3196)) + z5;
    tmp1 = (d5 * (16819 - 20995)) + (d3 * (25172 - 16069)) + z5;
    tmp2 = z5;
    tmp3 = z5;

    int rounder = (1 << (base_shift - 2 - 1));
    int shift_amount = base_shift - 2;

    dataptr[0] = (int16_t)(((tmp10 + tmp3) + rounder) >> shift_amount);
    dataptr[7] = (int16_t)(((tmp10 - tmp3) + rounder) >> shift_amount);
    dataptr[1] = (int16_t)(((tmp11 + tmp2) + rounder) >> shift_amount);
    dataptr[6] = (int16_t)(((tmp11 - tmp2) + rounder) >> shift_amount);
    dataptr[2] = (int16_t)(((tmp12 + tmp1) + rounder) >> shift_amount);
    dataptr[5] = (int16_t)(((tmp12 - tmp1) + rounder) >> shift_amount);
    dataptr[3] = (int16_t)(((tmp13 + tmp0) + rounder) >> shift_amount);
    dataptr[4] = (int16_t)(((tmp13 - tmp0) + rounder) >> shift_amount);

    dataptr += 8;
}
}
