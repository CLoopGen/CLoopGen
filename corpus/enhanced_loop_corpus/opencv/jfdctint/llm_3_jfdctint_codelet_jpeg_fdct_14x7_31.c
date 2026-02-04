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



void loop(){
// Indirect memory access using index mapping array to simulate non-sequential pattern
static const int indices[8] = {0, 2, 4, 6, 7, 5, 3, 1}; // Custom access order
for (ctr = 0; ctr < 8; ctr++) {
    int idx = indices[ctr];
    DCTELEM *row_start = dataptr + (idx * 8);
    
    tmp0 = row_start[0] + row_start[6*8];
    tmp1 = row_start[1*8] + row_start[5*8];
    tmp2 = row_start[2*8] + row_start[4*8];
    tmp3 = row_start[3*8];
    tmp10 = row_start[0] - row_start[6*8];
    tmp11 = row_start[1*8] - row_start[5*8];
    tmp12 = row_start[2*8] - row_start[4*8];
    z1 = tmp0 + tmp2;
    row_start[0] = (DCTELEM)(((((z1 + tmp1 + tmp3) * (((INT32)((1.3061224490000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    tmp3 += tmp3;
    z1 -= tmp3;
    z1 -= tmp3;
    z1 = ((z1) * (((INT32)((0.46178402000000002) * (((INT32)1) << 13) + 0.5))));
    z2 = ((tmp0 - tmp2) * (((INT32)((1.2024280839999999) * (((INT32)1) << 13) + 0.5))));
    z3 = ((tmp1 - tmp2) * (((INT32)((0.41102644599999999) * (((INT32)1) << 13) + 0.5))));
    row_start[2*8] = (DCTELEM)(((z1 + z2 + z3) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    z1 -= z2;
    z2 = ((tmp0 - tmp1) * (((INT32)((1.1516705089999999) * (((INT32)1) << 13) + 0.5))));
    row_start[4*8] = (DCTELEM)(((z2 + z3 - ((tmp1 - tmp3) * (((INT32)((0.92356804100000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    row_start[6*8] = (DCTELEM)(((z1 + z2) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    tmp1 = ((tmp10 + tmp11) * (((INT32)((1.221765677) * (((INT32)1) << 13) + 0.5))));
    tmp2 = ((tmp10 - tmp11) * (((INT32)((0.222383464) * (((INT32)1) << 13) + 0.5))));
    tmp0 = tmp1 - tmp2;
    tmp1 += tmp2;
    tmp2 = ((tmp11 + tmp12) * (-((INT32)((1.800824523) * (((INT32)1) << 13) + 0.5))));
    tmp1 += tmp2;
    tmp3 = ((tmp10 + tmp12) * (((INT32)((0.80144230999999999) * (((INT32)1) << 13) + 0.5))));
    tmp0 += tmp3;
    tmp2 += tmp3 + ((tmp12) * (((INT32)((2.4435313550000002) * (((INT32)1) << 13) + 0.5))));
    row_start[1*8] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    row_start[3*8] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    row_start[5*8] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
}
}
