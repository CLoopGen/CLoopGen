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
    ptrdiff_t indices[] = {0, 8, 16, 24, 32, 40, 48, 56};
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        DCTELEM *ptr = dataptr;
        tmp0 = ptr[indices[0]] + ptr[indices[7]];
        tmp1 = ptr[indices[1]] + ptr[indices[6]];
        tmp2 = ptr[indices[2]] + ptr[indices[5]];
        tmp3 = ptr[indices[3]] + ptr[indices[4]];
        tmp10 = tmp0 + tmp3;
        tmp12 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp13 = tmp1 - tmp2;
        tmp0 = ptr[indices[0]] - ptr[indices[7]];
        tmp1 = ptr[indices[1]] - ptr[indices[6]];
        tmp2 = ptr[indices[2]] - ptr[indices[5]];
        tmp3 = ptr[indices[3]] - ptr[indices[4]];
        ptr[indices[0]] = (DCTELEM)(((tmp10 + tmp11) + ((INT32)1 << ((2 + 1) - 1))) >> (2 + 1));
        ptr[indices[4]] = (DCTELEM)(((tmp10 - tmp11) + ((INT32)1 << ((2 + 1) - 1))) >> (2 + 1));
        z1 = ((tmp12 + tmp13) * (((INT32)4433)));
        ptr[indices[2]] = (DCTELEM)(((z1 + ((tmp12) * (((INT32)6270)))) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        ptr[indices[6]] = (DCTELEM)(((z1 - ((tmp13) * (((INT32)15137)))) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
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
        ptr[indices[1]] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        ptr[indices[3]] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        ptr[indices[5]] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        ptr[indices[7]] = (DCTELEM)(((tmp3) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
        dataptr++;
    }
}
