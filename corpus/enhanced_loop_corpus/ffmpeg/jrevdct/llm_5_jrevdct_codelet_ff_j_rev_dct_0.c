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

    // Introduce simplified control: only two cases — all AC coefficients zero or not
    // Eliminate fine-grained checks and merge logic into broader paths

    if ((d1 | d2 | d3 | d4 | d5 | d6 | d7) == 0) {
        // Still handle DC-only case for efficiency
        int16_t dcval = (int16_t)(d0 * (1 << 2));
        register int v = (dcval & 65535) | ((dcval * (1 << 16)) & 4294901760U);
        (((av_alias32 *)(&idataptr[0]))->u32 = (v));
        (((av_alias32 *)(&idataptr[4]))->u32 = (v));
        (((av_alias32 *)(&idataptr[8]))->u32 = (v));
        (((av_alias32 *)(&idataptr[12]))->u32 = (v));
        dataptr += 8;
        continue;
    }

    // Heavily simplified transform: assume full non-zero block and skip conditional variants
    // Remove all sub-branches and use fixed computation path for performance predictability

    tmp0 = (d0 + d4) * (((int32_t)1) << 13);
    tmp1 = (d0 - d4) * (((int32_t)1) << 13);

    // Assume d2 and d6 are non-zero (common case approximation)
    z1 = ((d2 + d6) * (4433));
    tmp2 = z1 + ((-d6) * (15137));
    tmp3 = z1 + ((d2) * (6270));

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    // Fixed final stage using averaged influence from d1-d7
    // Avoid branching by using direct arithmetic contributions scaled by sign

    int avg = (d1 + d3 + d5 + d7) / 4;
    z5 = avg * 9633;
    tmp0 = d7 * 2446 - d1 * 7373 - d3 * 16069 + z5;
    tmp1 = d5 * 16819 - d3 * 20995 - d5 * 3196 + z5;
    tmp2 = d3 * 25172 - d5 * 20995 - d7 * 16069 + z5;
    tmp3 = d1 * 12299 - d7 * 7373 - d1 * 3196 + z5;

    dataptr[0] = (int16_t)(((tmp10 + tmp3) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[7] = (int16_t)(((tmp10 - tmp3) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[1] = (int16_t)(((tmp11 + tmp2) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[6] = (int16_t)(((tmp11 - tmp2) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[2] = (int16_t)(((tmp12 + tmp1) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[5] = (int16_t)(((tmp12 - tmp1) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[3] = (int16_t)(((tmp13 + tmp0) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[4] = (int16_t)(((tmp13 - tmp0) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr += 8;
}
}
