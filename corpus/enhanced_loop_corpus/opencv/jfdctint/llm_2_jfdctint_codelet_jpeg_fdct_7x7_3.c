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
    for (ctr = 0; ctr < 7; ctr++) {
        DCTELEM *base_ptr = dataptr + 8 * ctr; // Change to consecutive base with offset per iteration

        tmp0 = base_ptr[0] + base_ptr[48]; // Strided access: 8*6 offset becomes 48
        tmp1 = base_ptr[8] + base_ptr[40];
        tmp2 = base_ptr[16] + base_ptr[32];
        tmp3 = base_ptr[24];
        tmp10 = base_ptr[0] - base_ptr[48];
        tmp11 = base_ptr[8] - base_ptr[40];
        tmp12 = base_ptr[16] - base_ptr[32];

        z1 = tmp0 + tmp2;
        base_ptr[0] = (DCTELEM)(((((z1 + tmp1 + tmp3) * (((INT32)((1.3061224490000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        tmp3 += tmp3;
        z1 -= tmp3;
        z1 -= tmp3;
        z1 = ((z1) * (((INT32)((0.46178402000000002) * (((INT32)1) << 13) + 0.5))));
        z2 = ((tmp0 - tmp2) * (((INT32)((1.2024280839999999) * (((INT32)1) << 13) + 0.5))));
        z3 = ((tmp1 - tmp2) * (((INT32)((0.41102644599999999) * (((INT32)1) << 13) + 0.5))));
        base_ptr[16] = (DCTELEM)(((z1 + z2 + z3) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        z1 -= z2;
        z2 = ((tmp0 - tmp1) * (((INT32)((1.1516705089999999) * (((INT32)1) << 13) + 0.5))));
        base_ptr[32] = (DCTELEM)(((z2 + z3 - ((tmp1 - tmp3) * (((INT32)((0.92356804100000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        base_ptr[48] = (DCTELEM)(((z1 + z2) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

        tmp1 = ((tmp10 + tmp11) * (((INT32)((1.221765677) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((tmp10 - tmp11) * (((INT32)((0.222383464) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp1 - tmp2;
        tmp1 += tmp2;
        tmp2 = ((tmp11 + tmp12) * (-((INT32)((1.800824523) * (((INT32)1) << 13) + 0.5))));
        tmp1 += tmp2;
        tmp3 = ((tmp10 + tmp12) * (((INT32)((0.80144230999999999) * (((INT32)1) << 13) + 0.5))));
        tmp0 += tmp3;
        tmp2 += tmp3 + ((tmp12) * (((INT32)((2.4435313550000002) * (((INT32)1) << 13) + 0.5))));

        base_ptr[8] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        base_ptr[24] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        base_ptr[40] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    }
}
