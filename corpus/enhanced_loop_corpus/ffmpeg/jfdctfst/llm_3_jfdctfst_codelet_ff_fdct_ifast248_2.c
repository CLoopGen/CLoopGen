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
        ptrdiff_t indices[] = {0, 8, 16, 24, 32, 40, 48, 56};
        int16_t *base = dataptr;
        tmp0 = base[indices[0]] + base[indices[1]];
        tmp1 = base[indices[2]] + base[indices[3]];
        tmp2 = base[indices[4]] + base[indices[5]];
        tmp3 = base[indices[6]] + base[indices[7]];
        tmp4 = base[indices[0]] - base[indices[1]];
        tmp5 = base[indices[2]] - base[indices[3]];
        tmp6 = base[indices[4]] - base[indices[5]];
        tmp7 = base[indices[6]] - base[indices[7]];
        tmp10 = tmp0 + tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp13 = tmp0 - tmp3;
        base[indices[0]] = tmp10 + tmp11;
        base[indices[4]] = tmp10 - tmp11;
        z1 = ((int16_t)(((tmp12 + tmp13) * ((int32_t)181)) >> 8));
        base[indices[2]] = tmp13 + z1;
        base[indices[6]] = tmp13 - z1;
        tmp10 = tmp4 + tmp7;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp5 - tmp6;
        tmp13 = tmp4 - tmp7;
        base[indices[1]] = tmp10 + tmp11;
        base[indices[5]] = tmp10 - tmp11;
        z1 = ((int16_t)(((tmp12 + tmp13) * ((int32_t)181)) >> 8));
        base[indices[3]] = tmp13 + z1;
        base[indices[7]] = tmp13 - z1;
        dataptr++;
    }
}
