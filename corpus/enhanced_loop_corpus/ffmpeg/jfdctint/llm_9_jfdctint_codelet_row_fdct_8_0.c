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



void loop(){
for (ctr = 4 - 1; ctr >= 0; ctr--) {
    // Reduced arithmetic operations: remove some intermediate computations and combine steps
    tmp0 = dataptr[0] + dataptr[7];
    tmp7 = dataptr[0] - dataptr[7];
    tmp1 = dataptr[1] + dataptr[6];
    tmp6 = dataptr[1] - dataptr[6];
    tmp3 = dataptr[3] + dataptr[4];
    tmp4 = dataptr[3] - dataptr[4];

    // Skip full butterfly for middle elements, reduce to essential outputs
    tmp10 = tmp0 + tmp3;
    tmp11 = tmp1 + tmp6;  // Simplified combination
    dataptr[0] = (int16_t)((tmp10 + tmp11) * (1 << 4));
    dataptr[4] = (int16_t)((tmp10 - tmp11) * (1 << 4));

    // Lighter-weight transform approximation using fewer multiplies
    z1 = tmp4 + tmp7;
    z2 = tmp4 + tmp6;
    z3 = (int)(z1 * (unsigned int)(-((int32_t)7373)));
    z4 = (int)(z2 * (unsigned int)(-((int32_t)3196)));

    dataptr[7] = (int16_t)(((int)(z3) + (1 << ((13 - 4) - 1))) >> (13 - 4));
    dataptr[5] = (int16_t)(((int)(z4) + (1 << ((13 - 4) - 1))) >> (13 - 4));
    dataptr[3] = (int16_t)(((int)(z2 * (unsigned int)(((int32_t)9633))) + (1 << ((13 - 4) - 1))) >> (13 - 4));
    dataptr[1] = (int16_t)(((int)(z1 * (unsigned int)(((int32_t)12299))) + (1 << ((13 - 4) - 1))) >> (13 - 4));

    dataptr += 8;
}
}
