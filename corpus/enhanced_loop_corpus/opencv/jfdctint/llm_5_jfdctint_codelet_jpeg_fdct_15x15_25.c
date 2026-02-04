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
extern INT32 tmp4;
extern INT32 tmp5;
extern INT32 tmp6;
extern INT32 tmp7;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    INT32 local_tmp0, local_tmp1, local_tmp2, local_tmp3, local_tmp4, local_tmp5, local_tmp6, local_tmp7;
    INT32 local_tmp10, local_tmp11, local_tmp12, local_tmp13, local_tmp14, local_tmp15, local_tmp16;
    INT32 local_z1, local_z2, local_z3;

    local_tmp0 = dataptr[8 * 0] + wsptr[8 * 6];
    local_tmp1 = dataptr[8 * 1] + wsptr[8 * 5];
    local_tmp2 = dataptr[8 * 2] + wsptr[8 * 4];
    local_tmp3 = dataptr[8 * 3] + wsptr[8 * 3];
    local_tmp4 = dataptr[8 * 4] + wsptr[8 * 2];
    local_tmp5 = dataptr[8 * 5] + wsptr[8 * 1];
    local_tmp6 = dataptr[8 * 6] + wsptr[8 * 0];
    local_tmp7 = dataptr[8 * 7];
    local_tmp10 = dataptr[8 * 0] - wsptr[8 * 6];
    local_tmp11 = dataptr[8 * 1] - wsptr[8 * 5];
    local_tmp12 = dataptr[8 * 2] - wsptr[8 * 4];
    local_tmp13 = dataptr[8 * 3] - wsptr[8 * 3];
    local_tmp14 = dataptr[8 * 4] - wsptr[8 * 2];
    local_tmp15 = dataptr[8 * 5] - wsptr[8 * 1];
    local_tmp16 = dataptr[8 * 6] - wsptr[8 * 0];

    local_z1 = local_tmp0 + local_tmp4 + local_tmp5;
    local_z2 = local_tmp1 + local_tmp3 + local_tmp6;
    local_z3 = local_tmp2 + local_tmp7;

    dataptr[8 * 0] = (DCTELEM)(((((local_z1 + local_z2 + local_z3) * (((INT32)((1.137777778) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    local_z3 += local_z3;
    dataptr[8 * 6] = (DCTELEM)(((((local_z1 - local_z3) * (((INT32)((1.3017575029999999) * (((INT32)1) << 13) + 0.5)))) - ((local_z2 - local_z3) * (((INT32)((0.49722712099999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

    local_tmp2 += ((local_tmp1 + local_tmp4) >> 1) - local_tmp7 - local_tmp7;
    local_z1 = ((local_tmp3 - local_tmp2) * (((INT32)((1.7420915749999999) * (((INT32)1) << 13) + 0.5)))) - ((local_tmp6 - local_tmp2) * (((INT32)((2.5466219570000002) * (((INT32)1) << 13) + 0.5))));
    local_z2 = ((local_tmp5 - local_tmp2) * (((INT32)((0.90847915599999995) * (((INT32)1) << 13) + 0.5)))) - ((local_tmp0 - local_tmp2) * (((INT32)((0.10394877399999999) * (((INT32)1) << 13) + 0.5))));
    local_z3 = ((local_tmp0 - local_tmp3) * (((INT32)((1.573898926) * (((INT32)1) << 13) + 0.5)))) + ((local_tmp6 - local_tmp5) * (((INT32)((1.0766718049999999) * (((INT32)1) << 13) + 0.5)))) + ((local_tmp1 - local_tmp4) * (((INT32)((0.89949231200000001) * (((INT32)1) << 13) + 0.5))));

    dataptr[8 * 2] = (DCTELEM)(((local_z1 + local_z3) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 4] = (DCTELEM)(((local_z2 + local_z3) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

    local_tmp2 = ((local_tmp10 - local_tmp12 - local_tmp13 + local_tmp15 + local_tmp16) * (((INT32)((1.393487498) * (((INT32)1) << 13) + 0.5))));
    local_tmp1 = ((local_tmp10 - local_tmp14 - local_tmp15) * (((INT32)((1.5303077249999999) * (((INT32)1) << 13) + 0.5)))) + ((local_tmp11 - local_tmp13 - local_tmp16) * (((INT32)((0.94578218700000005) * (((INT32)1) << 13) + 0.5))));
    local_tmp12 = (local_tmp12 * (((INT32)((1.393487498) * (((INT32)1) << 13) + 0.5))));
    local_tmp4 = ((local_tmp10 - local_tmp16) * (((INT32)((1.6002461610000001) * (((INT32)1) << 13) + 0.5)))) + ((local_tmp11 + local_tmp14) * (((INT32)((1.5303077249999999) * (((INT32)1) << 13) + 0.5)))) + ((local_tmp13 + local_tmp15) * (((INT32)((0.654463974) * (((INT32)1) << 13) + 0.5))));
    local_tmp0 = ((local_tmp13) * (((INT32)((0.54130120699999995) * (((INT32)1) << 13) + 0.5)))) - ((local_tmp14) * (((INT32)((0.58452553799999996) * (((INT32)1) << 13) + 0.5)))) + ((local_tmp16) * (((INT32)((1.9347887050000001) * (((INT32)1) << 13) + 0.5)))) + local_tmp4 + local_tmp12;
    local_tmp3 = ((local_tmp10) * (-((INT32)((0.40448097999999999) * (((INT32)1) << 13) + 0.5)))) - ((local_tmp11) * (((INT32)((2.4760899119999999) * (((INT32)1) << 13) + 0.5)))) - ((local_tmp15) * (((INT32)((0.98900651799999994) * (((INT32)1) << 13) + 0.5)))) + local_tmp4 - local_tmp12;

    dataptr[8 * 1] = (DCTELEM)(((local_tmp0) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 3] = (DCTELEM)(((local_tmp1) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 5] = (DCTELEM)(((local_tmp2) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 7] = (DCTELEM)(((local_tmp3) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

    dataptr++;
    wsptr++;
}
}
