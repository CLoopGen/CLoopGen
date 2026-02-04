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
for (rowctr = 4 - 1; rowctr >= 0; rowctr -= 2) {
    register uint8_t *idataptr0 = (uint8_t *)&dataptr[0];
    register uint8_t *idataptr1 = (uint8_t *)&dataptr[4];
    d0 = dataptr[0];
    d2 = dataptr[1];
    d4 = dataptr[2];
    d6 = dataptr[3];
    if ((d2 | d4 | d6) == 0) {
        if (d0) {
            int16_t dcval = (int16_t)(d0 << 2);
            register int v = (dcval & 65535) | ((dcval << 16) & 4294901760U);
            (((av_alias32 *)(&idataptr0[0]))->u32 = (v));
            (((av_alias32 *)(&idataptr0[4]))->u32 = (v));
            (((av_alias32 *)(&idataptr1[0]))->u32 = (v));
            (((av_alias32 *)(&idataptr1[4]))->u32 = (v));
        }
        dataptr += 16;
        continue;
    }
    z1 = ((d2 + d6) * (4433));
    tmp2 = z1 + ((-d6) * (15137));
    tmp3 = z1 + ((d2) * (6270));
    tmp0 = (d0 + d4) << 13;
    tmp1 = (d0 - d4) << 13;
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    int32_t scaled_tmp10 = ((tmp10) + (1 << 10)) >> 11;
    int32_t scaled_tmp11 = ((tmp11) + (1 << 10)) >> 11;
    int32_t scaled_tmp12 = ((tmp12) + (1 << 10)) >> 11;
    int32_t scaled_tmp13 = ((tmp13) + (1 << 10)) >> 11;

    dataptr[0] = (int16_t)scaled_tmp10;
    dataptr[1] = (int16_t)scaled_tmp11;
    dataptr[2] = (int16_t)scaled_tmp12;
    dataptr[3] = (int16_t)scaled_tmp13;

    if (rowctr > 0) {
        d0 = dataptr[8+0];
        d2 = dataptr[8+1];
        d4 = dataptr[8+2];
        d6 = dataptr[8+3];

        if ((d2 | d4 | d6) == 0) {
            if (d0) {
                int16_t dcval = (int16_t)(d0 << 2);
                register int v = (dcval & 65535) | ((dcval << 16) & 4294901760U);
                (((av_alias32 *)(&idataptr1[0]))->u32 = (v));
                (((av_alias32 *)(&idataptr1[4]))->u32 = (v));
            }
        } else {
            z1 = ((d2 + d6) * (4433));
            tmp2 = z1 + ((-d6) * (15137));
            tmp3 = z1 + ((d2) * (6270));
            tmp0 = (d0 + d4) << 13;
            tmp1 = (d0 - d4) << 13;
            tmp10 = tmp0 + tmp3;
            tmp13 = tmp0 - tmp3;
            tmp11 = tmp1 + tmp2;
            tmp12 = tmp1 - tmp2;

            dataptr[8+0] = (int16_t)(((tmp10) + (1 << 10)) >> 11);
            dataptr[8+1] = (int16_t)(((tmp11) + (1 << 10)) >> 11);
            dataptr[8+2] = (int16_t)(((tmp12) + (1 << 10)) >> 11);
            dataptr[8+3] = (int16_t)(((tmp13) + (1 << 10)) >> 11);
        }
    }

    dataptr += 16;
}
}
