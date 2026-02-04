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
    if ((d2 | d4 | d6) == 0) {
        if (d0) {
            int16_t dcval = (int16_t)(d0 << 2);
            register int v = (dcval & 65535) | ((dcval << 16) & 4294901760U);
            (((av_alias32 *)(&idataptr[0]))->u32 = (v));
            (((av_alias32 *)(&idataptr[4]))->u32 = (v));
        }
        dataptr += 8;
        continue;
    }
    tmp0 = (d0 + d4) << 13;
    tmp1 = (d0 - d4) << 13;
    if (d6) {
        if (d2) {
            z1 = ((d2 + d6) * (4433));
            tmp2 = z1 + ((-d6) * (15137));
            tmp3 = z1 + ((d2) * (6270));
        } else {
            tmp2 = ((-d6) * (10703));
            tmp3 = ((d6) * (4433));
        }
    } else {
        if (d2) {
            tmp2 = ((d2) * (4433));
            tmp3 = ((d2) * (10703));
        } else {
            tmp2 = 0;
            tmp3 = 0;
        }
    }
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    dataptr[0] = (int16_t)(((tmp10) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[1] = (int16_t)(((tmp11) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[2] = (int16_t)(((tmp12) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[3] = (int16_t)(((tmp13) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr += 8;
}
}
