#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
for (rowctr = 8 - 1; rowctr >= 0; rowctr -= 2) {
    d0 = dataptr[8 * 0];
    d2 = dataptr[8 * 1];
    d4 = dataptr[8 * 2];
    d6 = dataptr[8 * 3];

    z1 = (d2 + d6) * 4433;
    tmp0 = (d0 + d4) << 13;
    tmp1 = (d0 - d4) << 13;

    tmp2 = z1 + ((-d6) * 15137);
    tmp3 = z1 + (d2 * 6270);

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[8 * 0] = tmp10 >> 18;
    dataptr[8 * 1] = tmp11 >> 18;
    dataptr[8 * 2] = tmp12 >> 18;
    dataptr[8 * 3] = tmp13 >> 18;
    dataptr += 2;
}
}
