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
for (ctr = 0; ctr < 1; ctr++) {
    for (int i = 0; i < 3; i++) {
        tmp0 = dataptr[8 * 0] + dataptr[8 * 5];
        tmp11 = dataptr[8 * 1] + dataptr[8 * 4];
        tmp2 = dataptr[8 * 2] + dataptr[8 * 3];
        tmp10 = tmp0 + tmp2;
        tmp12 = tmp0 - tmp2;
        tmp0 = dataptr[8 * 0] - dataptr[8 * 5];
        tmp1 = dataptr[8 * 1] - dataptr[8 * 4];
        tmp2 = dataptr[8 * 2] - dataptr[8 * 3];
        dataptr[8 * 0] = (DCTELEM)(((((tmp10 + tmp11) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[8 * 2] = (DCTELEM)(((((tmp12) * (((INT32)((2.1773242160000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[8 * 4] = (DCTELEM)(((((tmp10 - tmp11 - tmp11) * (((INT32)((1.2570787219999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        tmp10 = ((tmp0 + tmp2) * (((INT32)((0.65071182900000002) * (((INT32)1) << 13) + 0.5))));
        dataptr[8 * 1] = (DCTELEM)(((tmp10 + ((tmp0 + tmp1) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[8 * 3] = (DCTELEM)(((((tmp0 - tmp1 - tmp2) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[8 * 5] = (DCTELEM)(((tmp10 + ((tmp2 - tmp1) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr++;
    }
}
}
