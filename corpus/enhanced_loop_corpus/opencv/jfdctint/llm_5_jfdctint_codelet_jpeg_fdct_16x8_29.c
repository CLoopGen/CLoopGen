#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    // Eliminate some loop-carried dependencies by reordering and precomputing values
    DCTELEM *cur_ptr = dataptr;
    INT32 d0 = cur_ptr[8 * 0], d1 = cur_ptr[8 * 1], d2 = cur_ptr[8 * 2], d3 = cur_ptr[8 * 3];
    INT32 d4 = cur_ptr[8 * 4], d5 = cur_ptr[8 * 5], d6 = cur_ptr[8 * 6], d7 = cur_ptr[8 * 7];

    tmp0 = d0 + d7; tmp1 = d1 + d6; tmp2 = d2 + d5; tmp3 = d3 + d4;
    tmp10 = tmp0 + tmp3;
    tmp12 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp13 = tmp1 - tmp2;

    // Remove redundant recomputation from original; store intermediate values earlier
    INT32 sub0 = d0 - d7, sub1 = d1 - d6, sub2 = d2 - d5, sub3 = d3 - d4;

    dataptr[8 * 0] = (DCTELEM)(((tmp10 + tmp11) + ((INT32)1 << ((2 + 1) - 1))) >> (2 + 1));
    dataptr[8 * 4] = (DCTELEM)(((tmp10 - tmp11) + ((INT32)1 << ((2 + 1) - 1))) >> (2 + 1));

    z1 = ((tmp12 + tmp13) * (((INT32)4433)));
    dataptr[8 * 2] = (DCTELEM)(((z1 + (tmp12 * ((INT32)6270))) + ((INT32)1 << (14))) >> 15);
    dataptr[8 * 6] = (DCTELEM)(((z1 - (tmp13 * ((INT32)15137))) + ((INT32)1 << 14)) >> 15);

    tmp12 = sub0 + sub2;
    tmp13 = sub1 + sub3;
    z1 = ((tmp12 + tmp13) * ((INT32)9633));
    INT32 t12_scaled = (tmp12 * (-(INT32)3196)) + z1;
    INT32 t13_scaled = (tmp13 * (-(INT32)16069)) + z1;

    z1 = ((sub0 + sub3) * (-(INT32)7373));
    tmp0 = (sub0 * (INT32)12299) + z1 + t12_scaled;
    tmp3 = (sub3 * (INT32)2446) + z1 + t13_scaled;

    z1 = ((sub1 + sub2) * (-(INT32)20995));
    tmp1 = (sub1 * (INT32)25172) + z1 + t13_scaled;
    tmp2 = (sub2 * (INT32)16819) + z1 + t12_scaled;

    // All writes happen at the end — reduced WAW hazards through scheduling
    dataptr[8 * 1] = (DCTELEM)((tmp0 + ((INT32)1 << 14)) >> 15);
    dataptr[8 * 3] = (DCTELEM)((tmp1 + ((INT32)1 << 14)) >> 15);
    dataptr[8 * 5] = (DCTELEM)((tmp2 + ((INT32)1 << 14)) >> 15);
    dataptr[8 * 7] = (DCTELEM)((tmp3 + ((INT32)1 << 14)) >> 15);

    dataptr++;
}
}
