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
extern unsigned int z1;
extern unsigned int z2;
extern unsigned int z3;
extern unsigned int z4;
extern unsigned int z5;
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access with Reverse and Offset Stride
    // Use a fixed stride pattern that jumps in reverse with non-unit increments
    int16_t *base = dataptr;
    int stride = 16; // Larger stride to simulate non-contiguous block access
    int indices[8] = {0, 7, 1, 6, 2, 5, 3, 4}; // Custom permutation index mapping

    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        int offset = ctr * stride; // Apply strided offset

        tmp0 = base[offset + indices[0]*8] + base[offset + indices[7]*8];
        tmp7 = base[offset + indices[0]*8] - base[offset + indices[7]*8];
        tmp1 = base[offset + indices[1]*8] + base[offset + indices[6]*8];
        tmp6 = base[offset + indices[1]*8] - base[offset + indices[6]*8];
        tmp2 = base[offset + indices[2]*8] + base[offset + indices[5]*8];
        tmp5 = base[offset + indices[2]*8] - base[offset + indices[5]*8];
        tmp3 = base[offset + indices[3]*8] + base[offset + indices[4]*8];
        tmp4 = base[offset + indices[3]*8] - base[offset + indices[4]*8];

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        base[offset + indices[0]*8] = (((int)(tmp10 + tmp11) + (1 << ((4) - 1))) >> (4));
        base[offset + indices[4]*8] = (((int)(tmp10 - tmp11) + (1 << ((4) - 1))) >> (4));

        z1 = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433)));
        base[offset + indices[2]*8] = (((int)(z1 + (int)((tmp13) * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        base[offset + indices[6]*8] = (((int)(z1 + (int)((tmp12) * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));

        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = (int)((z3 + z4) * (unsigned int)(((int32_t)9633)));

        tmp4 = (int)((tmp4) * (unsigned int)(((int32_t)2446)));
        tmp5 = (int)((tmp5) * (unsigned int)(((int32_t)16819)));
        tmp6 = (int)((tmp6) * (unsigned int)(((int32_t)25172)));
        tmp7 = (int)((tmp7) * (unsigned int)(((int32_t)12299)));

        z1 = (int)((z1) * (unsigned int)(-((int32_t)7373)));
        z2 = (int)((z2) * (unsigned int)(-((int32_t)20995)));
        z3 = (int)((z3) * (unsigned int)(-((int32_t)16069)));
        z4 = (int)((z4) * (unsigned int)(-((int32_t)3196)));

        z3 += z5;
        z4 += z5;

        base[offset + indices[7]*8] = (((int)(tmp4 + z1 + z3) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        base[offset + indices[5]*8] = (((int)(tmp5 + z2 + z4) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        base[offset + indices[3]*8] = (((int)(tmp6 + z2 + z3) + (1 << ((13 + 4) - 1))) >> (13 + 4));
        base[offset + indices[1]*8] = (((int)(tmp7 + z1 + z4) + (1 << ((13 + 4) - 1))) >> (13 + 4));
    }
}
