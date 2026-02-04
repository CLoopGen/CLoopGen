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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 5; ctr++) {
    DCTELEM *dptr = dataptr + ctr * 8;  // Convert to consecutive base pointer with offset
    DCTELEM *wptr = wsptr + ctr * 8;
    
    tmp0 = dptr[0] + wptr[8];
    tmp1 = dptr[8] + wptr[0];
    tmp12 = dptr[16] + dptr[56];
    tmp3 = dptr[24] + dptr[48];
    tmp4 = dptr[32] + dptr[40];
    tmp10 = tmp0 + tmp4;
    tmp13 = tmp0 - tmp4;
    tmp11 = tmp1 + tmp3;
    tmp14 = tmp1 - tmp3;
    tmp0 = dptr[0] - wptr[8];
    tmp1 = dptr[8] - wptr[0];
    tmp2 = dptr[16] - dptr[56];
    tmp3 = dptr[24] - dptr[48];
    tmp4 = dptr[32] - dptr[40];
    dptr[0] = (DCTELEM)(((((tmp10 + tmp11 + tmp12) * (((INT32)((1.28) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp12 += tmp12;
    dptr[32] = (DCTELEM)(((((tmp10 - tmp12) * (((INT32)((1.4644771910000001) * (((INT32)1) << 13) + 0.5)))) - ((tmp11 - tmp12) * (((INT32)((0.55938051099999997) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp10 = ((tmp13 + tmp14) * (((INT32)((1.064004961) * (((INT32)1) << 13) + 0.5))));
    dptr[16] = (DCTELEM)(((tmp10 + ((tmp13) * (((INT32)((0.65759122999999997) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dptr[48] = (DCTELEM)(((tmp10 - ((tmp14) * (((INT32)((2.7856011509999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp10 = tmp0 + tmp4;
    tmp11 = tmp1 - tmp3;
    dptr[40] = (DCTELEM)(((((tmp10 - tmp11 - tmp2) * (((INT32)((1.28) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp2 = ((tmp2) * (((INT32)((1.28) * (((INT32)1) << 13) + 0.5))));
    dptr[8] = (DCTELEM)(((((tmp0) * (((INT32)((1.7879068760000001) * (((INT32)1) << 13) + 0.5)))) + ((tmp1) * (((INT32)((1.6128940940000001) * (((INT32)1) << 13) + 0.5)))) + tmp2 + ((tmp3) * (((INT32)((0.82181058799999995) * (((INT32)1) << 13) + 0.5)))) + ((tmp4) * (((INT32)((0.28317662999999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp12 = ((tmp0 - tmp4) * (((INT32)((1.217352341) * (((INT32)1) << 13) + 0.5)))) - ((tmp1 + tmp3) * (((INT32)((0.75236512300000002) * (((INT32)1) << 13) + 0.5))));
    tmp13 = ((tmp10 + tmp11) * (((INT32)((0.395541753) * (((INT32)1) << 13) + 0.5)))) + ((tmp11) * (((INT32)((0.64000000000000001) * (((INT32)1) << 13) + 0.5)))) - tmp2;
    dptr[24] = (DCTELEM)(((tmp12 + tmp13) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dptr[56] = (DCTELEM)(((tmp12 - tmp13) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
}
}
