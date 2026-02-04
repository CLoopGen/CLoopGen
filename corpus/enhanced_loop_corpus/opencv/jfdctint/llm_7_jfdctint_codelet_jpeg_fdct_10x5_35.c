#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp11;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 16 - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[8 * 0] + dataptr[8 * 4];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 3];
    tmp2 = dataptr[8 * 2];
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp0 = dataptr[8 * 0] - dataptr[8 * 4];
    tmp1 = dataptr[8 * 1] - dataptr[8 * 3];

    const INT32 scale_factor = 1 << 13;
    const INT32 round_offset = 1 << 14;

    INT32 c1 = (INT32)(1.28 * scale_factor + 0.5);
    INT32 c2 = (INT32)(1.011928851 * scale_factor + 0.5);
    INT32 c3 = (INT32)(0.45254833999999999 * scale_factor + 0.5);
    INT32 c4 = (INT32)(1.064004961 * scale_factor + 0.5);
    INT32 c5 = (INT32)(0.65759122999999997 * scale_factor + 0.5);
    INT32 c6 = (INT32)(2.7856011509999998 * scale_factor + 0.5);

    INT32 sum_even = tmp10 + tmp2;
    INT32 diff_even = tmp10 - (tmp2 << 2);
    INT32 mixed_term = tmp11;

    dataptr[8 * 0] = (DCTELEM)(((sum_even * c1) + round_offset) >> 15);
    mixed_term = (mixed_term * c2) >> 13;
    diff_even = (diff_even * c3) >> 13;
    dataptr[8 * 2] = (DCTELEM)(((mixed_term + diff_even) + (1 << 14)) >> 15);
    dataptr[8 * 4] = (DCTELEM)(((mixed_term - diff_even) + (1 << 14)) >> 15);

    INT32 sum_odd_base = tmp0 + tmp1;
    tmp10 = (sum_odd_base * c4) >> 13;
    dataptr[8 * 1] = (DCTELEM)(((tmp10 + (tmp0 * c5)) + round_offset) >> 15);
    dataptr[8 * 3] = (DCTELEM)(((tmp10 - (tmp1 * c6)) + round_offset) >> 15);

    dataptr++;
    
    if (ctr == 8) {
        for (int i = 0; i < 4; i++) {
            dataptr[i] = (DCTELEM)((dataptr[i] + 1) & 0xFFFE);
        }
    }
}
}
