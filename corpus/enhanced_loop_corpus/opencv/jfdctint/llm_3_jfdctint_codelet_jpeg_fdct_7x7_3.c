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
    // Indirect memory access using index mapping array to simulate non-sequential access pattern
    int indices[7][8] = {
        {0, 8, 16, 24, 32, 40, 48, 56},
        {8, 0, 24, 16, 40, 32, 56, 48},
        {16, 24, 0, 8, 48, 56, 32, 40},
        {24, 16, 8, 0, 56, 48, 40, 32},
        {32, 40, 48, 56, 0, 8, 16, 24},
        {40, 32, 56, 48, 8, 0, 24, 16},
        {48, 56, 32, 40, 16, 24, 0, 8}
    };

    for (ctr = 0; ctr < 7; ctr++) {
        int *idx = indices[ctr]; // Use precomputed indirect indices

        tmp0 = dataptr[idx[0]] + dataptr[idx[6]];
        tmp1 = dataptr[idx[1]] + dataptr[idx[5]];
        tmp2 = dataptr[idx[2]] + dataptr[idx[4]];
        tmp3 = dataptr[idx[3]];
        tmp10 = dataptr[idx[0]] - dataptr[idx[6]];
        tmp11 = dataptr[idx[1]] - dataptr[idx[5]];
        tmp12 = dataptr[idx[2]] - dataptr[idx[4]];

        z1 = tmp0 + tmp2;
        dataptr[idx[0]] = (DCTELEM)(((((z1 + tmp1 + tmp3) * (((INT32)((1.3061224490000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        tmp3 += tmp3;
        z1 -= tmp3;
        z1 -= tmp3;
        z1 = ((z1) * (((INT32)((0.46178402000000002) * (((INT32)1) << 13) + 0.5))));
        z2 = ((tmp0 - tmp2) * (((INT32)((1.2024280839999999) * (((INT32)1) << 13) + 0.5))));
        z3 = ((tmp1 - tmp2) * (((INT32)((0.41102644599999999) * (((INT32)1) << 13) + 0.5))));
        dataptr[idx[2]] = (DCTELEM)(((z1 + z2 + z3) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        z1 -= z2;
        z2 = ((tmp0 - tmp1) * (((INT32)((1.1516705089999999) * (((INT32)1) << 13) + 0.5))));
        dataptr[idx[4]] = (DCTELEM)(((z2 + z3 - ((tmp1 - tmp3) * (((INT32)((0.92356804100000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[idx[6]] = (DCTELEM)(((z1 + z2) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

        tmp1 = ((tmp10 + tmp11) * (((INT32)((1.221765677) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((tmp10 - tmp11) * (((INT32)((0.222383464) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp1 - tmp2;
        tmp1 += tmp2;
        tmp2 = ((tmp11 + tmp12) * (-((INT32)((1.800824523) * (((INT32)1) << 13) + 0.5))));
        tmp1 += tmp2;
        tmp3 = ((tmp10 + tmp12) * (((INT32)((0.80144230999999999) * (((INT32)1) << 13) + 0.5))));
        tmp0 += tmp3;
        tmp2 += tmp3 + ((tmp12) * (((INT32)((2.4435313550000002) * (((INT32)1) << 13) + 0.5))));

        dataptr[idx[1]] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[idx[3]] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[idx[5]] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    }
}
