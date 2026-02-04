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



void loop() {
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        DCTELEM *base_ptr = dataptr;
        tmp0 = base_ptr[0] + base_ptr[56];
        tmp1 = base_ptr[8] + base_ptr[48];
        tmp2 = base_ptr[16] + base_ptr[40];
        tmp3 = base_ptr[24] + base_ptr[32];
        tmp10 = tmp0 + tmp3;
        tmp12 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp13 = tmp1 - tmp2;
        tmp0 = base_ptr[0] - base_ptr[56];
        tmp1 = base_ptr[8] - base_ptr[48];
        tmp2 = base_ptr[16] - base_ptr[40];
        tmp3 = base_ptr[24] - base_ptr[32];
        base_ptr[0] = (DCTELEM)(((tmp10 + tmp11) + ((INT32)1 << ((2 + 1) - 1))) >> (2 + 1));
        base_ptr[32] = (DCTELEM)(((tmp10 - tmp11) + ((INT32)1 << ((2 + 1) - 1))) >> (2 + 1));
        z1 = ((tmp12 + tmp13) * (((INT32)4433)));
        base_ptr[16] = (DCTELEM)(((z1 + ((tmp12) * (((INT32)6270)))) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        base_ptr[48] = (DCTELEM)(((z1 - ((tmp13) * (((INT32)15137)))) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        tmp12 = tmp0 + tmp2;
        tmp13 = tmp1 + tmp3;
        z1 = ((tmp12 + tmp13) * (((INT32)9633)));
        tmp12 = ((tmp12) * (-((INT32)3196)));
        tmp13 = ((tmp13) * (-((INT32)16069)));
        tmp12 += z1;
        tmp13 += z1;
        z1 = ((tmp0 + tmp3) * (-((INT32)7373)));
        tmp0 = ((tmp0) * (((INT32)12299)));
        tmp3 = ((tmp3) * (((INT32)2446)));
        tmp0 += z1 + tmp12;
        tmp3 += z1 + tmp13;
        z1 = ((tmp1 + tmp2) * (-((INT32)20995)));
        tmp1 = ((tmp1) * (((INT32)25172)));
        tmp2 = ((tmp2) * (((INT32)16819)));
        tmp1 += z1 + tmp13;
        tmp2 += z1 + tmp12;
        base_ptr[8] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        base_ptr[24] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        base_ptr[40] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        base_ptr[56] = (DCTELEM)(((tmp3) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        dataptr++;
    }
}
