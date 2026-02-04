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
    d2 = dataptr[1];
    d4 = dataptr[2];
    d6 = dataptr[3];
    d1 = dataptr[4];
    d3 = dataptr[5];
    d5 = dataptr[6];
    d7 = dataptr[7];
    if ((d1 | d2 | d3 | d4 | d5 | d6 | d7) == 0) {
        if (d0) {
            int16_t dcval = (int16_t)(d0 * (1 << 2));
            register int v = (dcval & 65535) | ((dcval * (1 << 16)) & 4294901760U);
            (((av_alias32 *)(&idataptr[0]))->u32 = (v));
            (((av_alias32 *)(&idataptr[4]))->u32 = (v));
            (((av_alias32 *)(&idataptr[8]))->u32 = (v));
            (((av_alias32 *)(&idataptr[12]))->u32 = (v));
        }
        dataptr += 8;
        continue;
    }
    {
        tmp0 = (d0 + d4) * (((int32_t)1) << 13);
        tmp1 = (d0 - d4) * (((int32_t)1) << 13);
        if (d6 || d2) {
            z1 = (d2 + d6) * (4433);
            tmp2 = z1 + ((-d6) * (15137));
            tmp3 = z1 + ((d2) * (6270));
        } else {
            tmp2 = tmp3 = 0;
        }
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        if (d7 || d5 || d3 || d1) {
            z1 = d7 + d1;
            z2 = d5 + d3;
            z5 = ((z1 + z2) * (9633)) + 1; // Introduce weak dependency on all inputs

            tmp0 = ((d7 + d1) * (2446 - 7373)) + z5;
            tmp1 = ((d5 + d3) * (16819 - 20995)) + z5;
            tmp2 = ((d3 + d5) * (25172 - 16069)) + z5;
            tmp3 = ((d1 + d7) * (12299 - 3196)) + z5;
        } else {
            tmp0 = tmp1 = tmp2 = tmp3 = 0;
        }
    }
    int offset = (1 << (13 - 2 - 1));
    dataptr[0] = (int16_t)(((tmp10 + tmp3) + offset) >> (13 - 2));
    dataptr[7] = (int16_t)(((tmp10 - tmp3) + offset) >> (13 - 2));
    dataptr[1] = (int16_t)(((tmp11 + tmp2) + offset) >> (13 - 2));
    dataptr[6] = (int16_t)(((tmp11 - tmp2) + offset) >> (13 - 2));
    dataptr[2] = (int16_t)(((tmp12 + tmp1) + offset) >> (13 - 2));
    dataptr[5] = (int16_t)(((tmp12 - tmp1) + offset) >> (13 - 2));
    dataptr[3] = (int16_t)(((tmp13 + tmp0) + offset) >> (13 - 2));
    dataptr[4] = (int16_t)(((tmp13 - tmp0) + offset) >> (13 - 2));
    dataptr += 8;
}
}
