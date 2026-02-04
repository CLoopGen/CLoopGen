#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp0;
extern int tmp1;
extern int tmp2;
extern int tmp3;
extern int tmp4;
extern int tmp5;
extern int tmp6;
extern int tmp7;
extern int tmp10;
extern int tmp11;
extern int tmp12;
extern int tmp13;
extern int z1;
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int offsets[] = {0, 2, 4, 6, 1, 3, 5, 7};
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        int16_t vals[8];
        for (int i = 0; i < 8; i++) {
            vals[i] = dataptr[offsets[i] * 8];
        }
        tmp0 = vals[0] + vals[1];
        tmp1 = vals[2] + vals[3];
        tmp2 = vals[4] + vals[5];
        tmp3 = vals[6] + vals[7];
        tmp4 = vals[0] - vals[1];
        tmp5 = vals[2] - vals[3];
        tmp6 = vals[4] - vals[5];
        tmp7 = vals[6] - vals[7];
        tmp10 = tmp0 + tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp13 = tmp0 - tmp3;
        dataptr[offsets[0]*8] = (((int)(tmp10 + tmp11) + (1 << ((4) - 1))) >> (4));
        dataptr[offsets[4]*8] = (((int)(tmp10 - tmp11) + (1 << ((4) - 1))) >> (4));
        z1 = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433)));
        dataptr[offsets[2]*8] = (((int)(z1 + (int)((tmp13) * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        dataptr[offsets[6]*8] = (((int)(z1 + (int)((tmp12) * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        tmp10 = tmp4 + tmp7;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp5 - tmp6;
        tmp13 = tmp4 - tmp7;
        dataptr[offsets[1]*8] = (((int)(tmp10 + tmp11) + (1 << ((4) - 1))) >> (4));
        dataptr[offsets[5]*8] = (((int)(tmp10 - tmp11) + (1 << ((4) - 1))) >> (4));
        z1 = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433)));
        dataptr[offsets[3]*8] = (((int)(z1 + (int)((tmp13) * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        dataptr[offsets[7]*8] = (((int)(z1 + (int)((tmp12) * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        dataptr++;
    }
}
