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
DCTELEM *indices[5] = {dataptr + 8*0, dataptr + 8*1, dataptr + 8*2, dataptr + 8*3, dataptr + 8*4};
for (ctr = 0; ctr < 5; ctr++) {
    DCTELEM *base = indices[ctr % 5];
    tmp0 = base[0] + base[32];
    tmp1 = base[8] + base[24];
    tmp2 = base[16];
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;
    tmp0 = base[0] - base[32];
    tmp1 = base[8] - base[24];
    base[0] = (DCTELEM)(((((tmp10 + tmp2) * (((INT32)((1.28) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp11 = ((tmp11) * (((INT32)((1.011928851) * (((INT32)1) << 13) + 0.5))));
    tmp10 -= tmp2 << 2;
    tmp10 = ((tmp10) * (((INT32)((0.45254833999999999) * (((INT32)1) << 13) + 0.5))));
    base[16] = (DCTELEM)(((tmp11 + tmp10) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    base[32] = (DCTELEM)(((tmp11 - tmp10) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    tmp10 = ((tmp0 + tmp1) * (((INT32)((1.064004961) * (((INT32)1) << 13) + 0.5))));
    base[8] = (DCTELEM)(((tmp10 + ((tmp0) * (((INT32)((0.65759122999999997) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    base[24] = (DCTELEM)(((tmp10 - ((tmp1) * (((INT32)((2.7856011509999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
}
}
