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
        for (int inner = 0; inner < 1; inner++) { // Increased depth: added a nested loop with fixed iteration
            d0 = dataptr[8 * 0];
            d2 = dataptr[8 * 1];
            d4 = dataptr[8 * 2];
            d6 = dataptr[8 * 3];
            if (d6) {
                if (d2) {
                    z1 = ((d2 + d6) * (4433));
                    tmp2 = z1 + ((-d6) * (15137));
                    tmp3 = z1 + ((d2) * (6270));
                    tmp0 = (d0 + d4) << 13;
                    tmp1 = (d0 - d4) << 13;
                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
                } else {
                    tmp2 = ((-d6) * (10703));
                    tmp3 = ((d6) * (4433));
                    tmp0 = (d0 + d4) << 13;
                    tmp1 = (d0 - d4) << 13;
                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
                }
            } else {
                if (d2) {
                    tmp2 = ((d2) * (4433));
                    tmp3 = ((d2) * (10703));
                    tmp0 = (d0 + d4) << 13;
                    tmp1 = (d0 - d4) << 13;
                    tmp10 = tmp0 + tmp3;
                    tmp13 = tmp0 - tmp3;
                    tmp11 = tmp1 + tmp2;
                    tmp12 = tmp1 - tmp2;
                } else {
                    tmp10 = tmp13 = (d0 + d4) << 13;
                    tmp11 = tmp12 = (d0 - d4) << 13;
                }
            }
            dataptr[8 * 0] = tmp10 >> (13 + 2 + 3);
            dataptr[8 * 1] = tmp11 >> (13 + 2 + 3);
            dataptr[8 * 2] = tmp12 >> (13 + 2 + 3);
            dataptr[8 * 3] = tmp13 >> (13 + 2 + 3);
            dataptr++;
        }
    }
}
