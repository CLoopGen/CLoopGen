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
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        int16_t *base_ptr = dataptr;
        tmp0 = base_ptr[0] + base_ptr[8];
        tmp1 = base_ptr[16] + base_ptr[24];
        tmp2 = base_ptr[32] + base_ptr[40];
        tmp3 = base_ptr[48] + base_ptr[56];
        tmp4 = base_ptr[0] - base_ptr[8];
        tmp5 = base_ptr[16] - base_ptr[24];
        tmp6 = base_ptr[32] - base_ptr[40];
        tmp7 = base_ptr[48] - base_ptr[56];
        tmp10 = tmp0 + tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp13 = tmp0 - tmp3;
        base_ptr[0] = (((int)(tmp10 + tmp11) + (1 << ((4) - 1))) >> (4));
        base_ptr[32] = (((int)(tmp10 - tmp11) + (1 << ((4) - 1))) >> (4));
        z1 = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433)));
        base_ptr[16] = (((int)(z1 + (int)((tmp13) * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        base_ptr[48] = (((int)(z1 + (int)((tmp12) * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        tmp10 = tmp4 + tmp7;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp5 - tmp6;
        tmp13 = tmp4 - tmp7;
        base_ptr[8] = (((int)(tmp10 + tmp11) + (1 << ((4) - 1))) >> (4));
        base_ptr[40] = (((int)(tmp10 - tmp11) + (1 << ((4) - 1))) >> (4));
        z1 = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433)));
        base_ptr[24] = (((int)(z1 + (int)((tmp13) * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        base_ptr[56] = (((int)(z1 + (int)((tmp12) * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        dataptr += 8;
    }
}
