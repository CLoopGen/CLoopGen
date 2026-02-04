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
for (rowctr = 4 - 1; rowctr >= 0; rowctr--) {
    d0 = dataptr[8 * 0];
    d2 = dataptr[8 * 1];
    d4 = dataptr[8 * 2];
    d6 = dataptr[8 * 3];

    int32_t local_tmp0, local_tmp1, local_tmp2, local_tmp3;
    int32_t local_tmp10, local_tmp11, local_tmp12, local_tmp13;

    local_tmp0 = (d0 + d4) << 13;
    local_tmp1 = (d0 - d4) << 13;

    if (d6) {
        if (d2) {
            z1 = ((d2 + d6) * (4433));
            local_tmp2 = z1 + ((-d6) * (15137));
            local_tmp3 = z1 + ((d2) * (6270));
        } else {
            local_tmp2 = ((-d6) * (10703));
            local_tmp3 = ((d6) * (4433));
        }
    } else {
        if (d2) {
            local_tmp2 = ((d2) * (4433));
            local_tmp3 = ((d2) * (10703));
        } else {
            local_tmp2 = 0;
            local_tmp3 = 0;
        }
    }

    local_tmp10 = local_tmp0 + local_tmp3;
    local_tmp13 = local_tmp0 - local_tmp3;
    local_tmp11 = local_tmp1 + local_tmp2;
    local_tmp12 = local_tmp1 - local_tmp2;

    dataptr[8 * 0] = local_tmp10 >> (13 + 2 + 3);
    dataptr[8 * 1] = local_tmp11 >> (13 + 2 + 3);
    dataptr[8 * 2] = local_tmp12 >> (13 + 2 + 3);
    dataptr[8 * 3] = local_tmp13 >> (13 + 2 + 3);

    dataptr++;
}
}
