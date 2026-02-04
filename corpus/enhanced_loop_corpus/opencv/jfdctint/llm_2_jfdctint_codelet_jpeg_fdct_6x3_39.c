#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ctr = 0; ctr < 6; ctr++) {
        tmp0 = dataptr[0] + dataptr[16];
        tmp1 = dataptr[8];
        tmp2 = dataptr[0] - dataptr[16];
        dataptr[0] = (DCTELEM)((((tmp0 + tmp1) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << (15))) >> 15);
        dataptr[16] = (DCTELEM)((((tmp0 - tmp1 - tmp1) * (((INT32)((1.2570787219999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << (15))) >> 15);
        dataptr[8] = (DCTELEM)((((tmp2) * (((INT32)((2.1773242160000001) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << (15))) >> 15);
        dataptr += 8;
    }
}
