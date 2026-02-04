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
    int32_t local_d0 = d0, local_d2 = d2, local_d4 = d4, local_d6 = d6;
    if ((local_d2 | local_d4 | local_d6) == 0) {
        if (local_d0) {
            int16_t dcval = (int16_t)(local_d0 << 2);
            register int v = (dcval & 65535) | ((dcval << 16) & 4294901760U);
            (((av_alias32 *)(&idataptr[0]))->u32 = (v));
            (((av_alias32 *)(&idataptr[4]))->u32 = (v));
        }
        dataptr += 8;
        continue;
    }
    int32_t t0, t1, t2, t3, t10, t11, t12, t13;
    t0 = (local_d0 + local_d4) << 13;
    t1 = (local_d0 - local_d4) << 13;
    if (local_d6) {
        if (local_d2) {
            z1 = ((local_d2 + local_d6) * (4433));
            t2 = z1 + ((-local_d6) * (15137));
            t3 = z1 + ((local_d2) * (6270));
        } else {
            t2 = ((-local_d6) * (10703));
            t3 = ((local_d6) * (4433));
        }
    } else {
        if (local_d2) {
            t2 = ((local_d2) * (4433));
            t3 = ((local_d2) * (10703));
        } else {
            t2 = t0;
            t3 = t1;
        }
    }
    t10 = t0 + t3;
    t13 = t0 - t3;
    t11 = t1 + t2;
    t12 = t1 - t2;
    dataptr[0] = (int16_t)(((t10) + (((int32_t)1) << (11))) >> (11));
    dataptr[1] = (int16_t)(((t11) + (((int32_t)1) << (11))) >> (11));
    dataptr[2] = (int16_t)(((t12) + (((int32_t)1) << (11))) >> (11));
    dataptr[3] = (int16_t)(((t13) + (((int32_t)1) << (11))) >> (11));
    dataptr += 8;
}
}
