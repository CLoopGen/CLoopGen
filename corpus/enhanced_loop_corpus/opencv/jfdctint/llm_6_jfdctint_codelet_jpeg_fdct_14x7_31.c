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
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    INT32 t0 = dataptr[8 * 0] + dataptr[8 * 6];
    INT32 t1 = dataptr[8 * 1] + dataptr[8 * 5];
    INT32 t2 = dataptr[8 * 2] + dataptr[8 * 4];
    INT32 t3 = dataptr[8 * 3];
    INT32 u10 = dataptr[8 * 0] - dataptr[8 * 6];
    INT32 u11 = dataptr[8 * 1] - dataptr[8 * 5];
    INT32 u12 = dataptr[8 * 2] - dataptr[8 * 4];
    INT32 z1 = t0 + t2;
    INT32 temp_val = ((((z1 + t1 + t3) * (((INT32)((1.3061224490000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1);
    dataptr[8 * 0] = (DCTELEM)temp_val;
    t3 += t3;
    z1 -= t3;
    z1 -= t3;
    z1 = ((z1) * (((INT32)((0.46178402000000002) * (((INT32)1) << 13) + 0.5))));
    INT32 z2 = ((t0 - t2) * (((INT32)((1.2024280839999999) * (((INT32)1) << 13) + 0.5))));
    INT32 z3 = ((t1 - t2) * (((INT32)((0.41102644599999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[8 * 2] = (DCTELEM)(((z1 + z2 + z3) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    z1 -= z2;
    z2 = ((t0 - t1) * (((INT32)((1.1516705089999999) * (((INT32)1) << 13) + 0.5))));
    dataptr[8 * 4] = (DCTELEM)(((z2 + z3 - ((t1 - t3) * (((INT32)((0.92356804100000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    dataptr[8 * 6] = (DCTELEM)(((z1 + z2) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    INT32 p1 = ((u10 + u11) * (((INT32)((1.221765677) * (((INT32)1) << 13) + 0.5))));
    INT32 p2 = ((u10 - u11) * (((INT32)((0.222383464) * (((INT32)1) << 13) + 0.5))));
    INT32 q0 = p1 - p2;
    INT32 q1 = p1 + p2;
    INT32 q2 = ((u11 + u12) * (-((INT32)((1.800824523) * (((INT32)1) << 13) + 0.5))));
    q1 += q2;
    INT32 q3 = ((u10 + u12) * (((INT32)((0.80144230999999999) * (((INT32)1) << 13) + 0.5))));
    q0 += q3;
    q2 += q3 + ((u12) * (((INT32)((2.4435313550000002) * (((INT32)1) << 13) + 0.5))));
    dataptr[8 * 1] = (DCTELEM)(((q0) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    dataptr[8 * 3] = (DCTELEM)(((q1) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    dataptr[8 * 5] = (DCTELEM)(((q2) + ((INT32)1 << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
    dataptr++;
}
}
