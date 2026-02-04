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
extern INT32 tmp12;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    INT32 load0 = dataptr[8 * 0];
    INT32 load1 = dataptr[8 * 1];
    INT32 load2 = dataptr[8 * 2];
    INT32 load3 = dataptr[8 * 3];
    INT32 load4 = dataptr[8 * 4];
    INT32 load5 = dataptr[8 * 5];
    tmp0 = load0 + load5;
    tmp11 = load1 + load4;
    tmp2 = load2 + load3;
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    tmp0 = load0 - load5;
    tmp1 = load1 - load4;
    tmp2 = load2 - load3;
    INT32 t10_shifted = (13 + 2 + 1);
    INT32 rounder = (INT32)1 << (t10_shifted - 1);
    INT32 coef_17778 = (INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5);
    INT32 coef_21773 = (INT32)((2.1773242160000001) * (((INT32)1) << 13) + 0.5);
    INT32 coef_12571 = (INT32)((1.2570787219999999) * (((INT32)1) << 13) + 0.5);
    INT32 coef_06507 = (INT32)((0.65071182900000002) * (((INT32)1) << 13) + 0.5);
    dataptr[8 * 0] = (DCTELEM)((((tmp10 + tmp11) * coef_17778) + rounder) >> t10_shifted);
    dataptr[8 * 2] = (DCTELEM)(((tmp12 * coef_21773) + rounder) >> t10_shifted);
    dataptr[8 * 4] = (DCTELEM)((((tmp10 - tmp11 - tmp11) * coef_12571) + rounder) >> t10_shifted);
    tmp10 = ((tmp0 + tmp2) * coef_06507);
    dataptr[8 * 1] = (DCTELEM)(((tmp10 + (tmp0 + tmp1) * coef_17778) + rounder) >> t10_shifted);
    dataptr[8 * 3] = (DCTELEM)((((tmp0 - tmp1 - tmp2) * coef_17778) + rounder) >> t10_shifted);
    dataptr[8 * 5] = (DCTELEM)(((tmp10 + (tmp2 - tmp1) * coef_17778) + rounder) >> t10_shifted);
    dataptr++;
}
}
