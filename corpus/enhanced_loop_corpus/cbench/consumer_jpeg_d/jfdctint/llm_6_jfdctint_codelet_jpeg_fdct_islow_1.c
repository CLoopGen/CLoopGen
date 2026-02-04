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
    tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
    tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
    tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
    tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
    tmp5 = dataptr[8 * 2] - dataptr[8 * 5];
    tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
    tmp4 = dataptr[8 * 3] - dataptr[8 * 4];

    // Introduce temporary variables to break WAW and WAR dependencies
    INT32 t10 = tmp0 + tmp3;
    INT32 t13 = tmp0 - tmp3;
    INT32 t11 = tmp1 + tmp2;
    INT32 t12 = tmp1 - tmp2;

    // Use temporaries to eliminate write-after-write on dataptr updates
    DCTELEM out0 = (DCTELEM)(((t10 + t11) + (((INT32)1) << ((2) - 1))) >> (2));
    DCTELEM out4 = (DCTELEM)(((t10 - t11) + (((INT32)1) << ((2) - 1))) >> (2));

    z1 = ((t12 + t13) * (((INT32)4433)));
    DCTELEM out2 = (DCTELEM)(((z1 + ((t13) * (((INT32)6270)))) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));
    DCTELEM out6 = (DCTELEM)(((z1 + ((t12) * (-((INT32)15137)))) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    z5 = ((z3 + z4) * (((INT32)9633)));

    INT32 s4 = ((tmp4) * (((INT32)2446)));
    INT32 s5 = ((tmp5) * (((INT32)16819)));
    INT32 s6 = ((tmp6) * (((INT32)25172)));
    INT32 s7 = ((tmp7) * (((INT32)12299)));
    INT32 sz1 = ((z1) * (-((INT32)7373)));
    INT32 sz2 = ((z2) * (-((INT32)20995)));
    INT32 sz3 = ((z3) * (-((INT32)16069)));
    INT32 sz4 = ((z4) * (-((INT32)3196)));

    sz3 += z5;
    sz4 += z5;

    DCTELEM out7 = (DCTELEM)(((s4 + sz1 + sz3) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));
    DCTELEM out5 = (DCTELEM)(((s5 + sz2 + sz4) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));
    DCTELEM out3 = (DCTELEM)(((s6 + sz2 + sz3) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));
    DCTELEM out1 = (DCTELEM)(((s7 + sz1 + sz4) + (((INT32)1) << ((13 + 2) - 1))) >> (13 + 2));

    // Final store with no intra-loop data dependency
    dataptr[8 * 0] = out0;
    dataptr[8 * 4] = out4;
    dataptr[8 * 2] = out2;
    dataptr[8 * 6] = out6;
    dataptr[8 * 7] = out7;
    dataptr[8 * 5] = out5;
    dataptr[8 * 3] = out3;
    dataptr[8 * 1] = out1;

    dataptr++;
}
}
