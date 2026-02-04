#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp4;
extern INT32 tmp5;
extern INT32 tmp6;
extern INT32 tmp7;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    // Eliminate redundant dependencies and reorganize operations to minimize data hazards
    // All temporary variables are computed independently where possible
    // No loop-carried dependencies introduced; full independence across iterations

    INT32 d0 = dataptr[0], d1 = dataptr[1], d2 = dataptr[2], d3 = dataptr[3];
    INT32 d4 = dataptr[4], d5 = dataptr[5], d6 = dataptr[6], d7 = dataptr[7];

    INT32 t0 = d0 + d7;
    INT32 t7 = d0 - d7;
    INT32 t1 = d1 + d6;
    INT32 t6 = d1 - d6;
    INT32 t2 = d2 + d5;
    INT32 t5 = d2 - d5;
    INT32 t3 = d3 + d4;
    INT32 t4 = d3 - d4;

    INT32 t10 = t0 + t3;
    INT32 t13 = t0 - t3;
    INT32 t11 = t1 + t2;
    INT32 t12 = t1 - t2;

    // Compute all outputs without intermediate overwrites (avoid WAW)
    INT32 out0 = (t10 + t11) << 2;
    INT32 out4 = (t10 - t11) << 2;

    z1 = (t12 + t13) * 4433LL;
    INT32 out2 = (z1 + t13 * 6270 + (1LL << (11))) >> 11;
    INT32 out6 = (z1 + t12 * (-15137) + (1LL << (11))) >> 11;

    z1 = t4 + t7;
    z2 = t5 + t6;
    z3 = t4 + t6;
    z4 = t5 + t7;
    z5 = (z3 + z4) * 9633LL;

    t4 = t4 * 2446LL;
    t5 = t5 * 16819LL;
    t6 = t6 * 25172LL;
    t7 = t7 * 12299LL;

    z1 = z1 * (-7373LL);
    z2 = z2 * (-20995LL);
    z3 = z3 * (-16069LL);
    z4 = z4 * (-3196LL);

    z3 += z5;
    z4 += z5;

    INT32 out7 = (t4 + z1 + z3 + (1LL << 11)) >> 11;
    INT32 out5 = (t5 + z2 + z4 + (1LL << 11)) >> 11;
    INT32 out3 = (t6 + z2 + z3 + (1LL << 11)) >> 11;
    INT32 out1 = (t7 + z1 + z4 + (1LL << 11)) >> 11;

    // Final store to memory — eliminates WAR/WAW during computation
    dataptr[0] = (DCTELEM)out0;
    dataptr[4] = (DCTELEM)out4;
    dataptr[2] = (DCTELEM)out2;
    dataptr[6] = (DCTELEM)out6;
    dataptr[7] = (DCTELEM)out7;
    dataptr[5] = (DCTELEM)out5;
    dataptr[3] = (DCTELEM)out3;
    dataptr[1] = (DCTELEM)out1;

    dataptr += 8;
}
}
