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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 4 - 1; ctr >= 0; ctr--) {
        tmp0 = dataptr[8 * 0] + dataptr[8 * 6];
        tmp1 = dataptr[8 * 1] + dataptr[8 * 5];
        tmp2 = dataptr[8 * 2] + dataptr[8 * 4];
        tmp3 = dataptr[8 * 3];
        tmp10 = dataptr[8 * 0] - dataptr[8 * 6];
        tmp11 = dataptr[8 * 1] - dataptr[8 * 5];
        tmp12 = dataptr[8 * 2] - dataptr[8 * 4];
        z1 = tmp0 + tmp2;
        dataptr[8 * 0] = (DCTELEM)((((z1 + tmp1 + tmp3) * (((INT32)((1.306122449) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << (15))) >> 16);
        tmp3 += tmp3;
        z1 -= tmp3;
        z1 = ((z1) * (((INT32)((0.461784020) * (((INT32)1) << 13) + 0.5))));
        z2 = ((tmp0 - tmp2) * (((INT32)((1.202428084) * (((INT32)1) << 13) + 0.5))));
        dataptr[8 * 2] = (DCTELEM)(((z1 + z2) + ((INT32)1 << 15)) >> 16);
        z2 = ((tmp0 - tmp1) * (((INT32)((1.151670509) * (((INT32)1) << 13) + 0.5))));
        dataptr[8 * 4] = (DCTELEM)(((z2 - ((tmp1 - tmp3) * (((INT32)((0.923568041) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << 15)) >> 16);
        dataptr[8 * 6] = (DCTELEM)(((z1 + z2) + ((INT32)1 << 15)) >> 16);
        tmp1 = ((tmp10 + tmp11) * (((INT32)((1.221765677) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((tmp10 - tmp11) * (((INT32)((0.222383464) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp1 - tmp2;
        tmp1 += tmp2;
        tmp3 = ((tmp10 + tmp12) * (((INT32)((0.801442310) * (((INT32)1) << 13) + 0.5))));
        tmp0 += tmp3;
        tmp2 += tmp3;
        dataptr[8 * 1] = (DCTELEM)(((tmp0) + ((INT32)1 << 15)) >> 16);
        dataptr[8 * 3] = (DCTELEM)(((tmp1) + ((INT32)1 << 15)) >> 16);
        dataptr++;
    }
}
