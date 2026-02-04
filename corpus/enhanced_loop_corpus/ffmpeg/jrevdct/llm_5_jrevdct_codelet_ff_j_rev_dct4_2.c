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
extern int32_t d0;
extern int32_t d2;
extern int32_t d4;
extern int32_t d6;
extern int16_t *dataptr;
extern int rowctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rowctr = 4 - 1; rowctr >= 0; rowctr--) {
    register uint8_t *idataptr = (uint8_t *)dataptr;
    d0 = dataptr[0];
    d2 = dataptr[1];
    d4 = dataptr[2];
    d6 = dataptr[3];

    int non_zero_fast_path = ((d2 | d4 | d6) == 0) && d0;
    int compute_transform = 1;

    if (non_zero_fast_path) {
        int16_t dcval = (int16_t)(d0 << 2);
        register int v = (dcval & 65535) | ((dcval << 16) & 4294901760U);
        (((av_alias32 *)(&idataptr[0]))->u32 = (v));
        (((av_alias32 *)(&idataptr[4]))->u32 = (v));
        compute_transform = 0;
    }

    if (compute_transform) {
        if (d6 && d2) {
            z1 = ((d2 + d6) * 4433);
            tmp2 = z1 - (d6 * 15137);
            tmp3 = z1 + (d2 * 6270);
        } else if (d6) {
            tmp2 = -10703 * d6;
            tmp3 = 4433 * d6;
        } else if (d2) {
            tmp2 = 4433 * d2;
            tmp3 = 10703 * d2;
        } else {
            tmp10 = tmp13 = (d0 + d4) << 13;
            tmp11 = tmp12 = (d0 - d4) << 13;
            goto store_results;
        }

        tmp0 = (d0 + d4) << 13;
        tmp1 = (d0 - d4) << 13;
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
    }

store_results:
    if (compute_transform) {
        dataptr[0] = (int16_t)((tmp10 + (1 << 10)) >> 11);
        dataptr[1] = (int16_t)((tmp11 + (1 << 10)) >> 11);
        dataptr[2] = (int16_t)((tmp12 + (1 << 10)) >> 11);
        dataptr[3] = (int16_t)((tmp13 + (1 << 10)) >> 11);
    }
    dataptr += 8;
}
}
