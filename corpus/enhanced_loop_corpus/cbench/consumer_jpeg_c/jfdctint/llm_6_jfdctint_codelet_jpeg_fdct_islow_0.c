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



void loop() {
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        tmp0 = dataptr[0] + dataptr[7];
        tmp7 = dataptr[0] - dataptr[7];
        tmp1 = dataptr[1] + dataptr[6];
        tmp6 = dataptr[1] - dataptr[6];
        tmp2 = dataptr[2] + dataptr[5];
        tmp5 = dataptr[2] - dataptr[5];
        tmp3 = dataptr[3] + dataptr[4];
        tmp4 = dataptr[3] - dataptr[4];

        // Introduce temporary variables to break WAW and WAR dependencies
        INT32 t10 = tmp0 + tmp3;
        INT32 t13 = tmp0 - tmp3;
        INT32 t11 = tmp1 + tmp2;
        INT32 t12 = tmp1 - tmp2;

        // Reorder independent computations to reduce artificial dependencies
        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;

        dataptr[0] = (DCTELEM)((t10 + t11) << 2);
        dataptr[4] = (DCTELEM)((t10 - t11) << 2);

        INT32 z5 = ((t12 + t13) * (((INT32)4433)));
        INT32 temp2 = ((z5 + ((t13) * (((INT32)6270)))) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2);
        INT32 temp6 = ((z5 + ((t12) * (-((INT32)15137)))) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2);

        // Delayed assignment to break loop-carried dependency on z1-z4
        z1 = ((z1) * (-((INT32)7373)));
        z2 = ((z2) * (-((INT32)20995)));
        z3 = ((z3) * (-((INT32)16069)));
        z4 = ((z4) * (-((INT32)3196)));

        INT32 t5 = ((tmp5) * (((INT32)16819)));
        INT32 t6 = ((tmp6) * (((INT32)25172)));
        INT32 t7 = ((tmp7) * (((INT32)12299)));
        INT32 t4 = ((tmp4) * (((INT32)2446)));

        INT32 z5_full = ((z3 + z4) * (((INT32)9633)));
        z3 += z5_full;
        z4 += z5_full;

        dataptr[2] = (DCTELEM)(temp2);
        dataptr[6] = (DCTELEM)(temp6);
        dataptr[7] = (DCTELEM)(((t4 + z1 + z3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[5] = (DCTELEM)(((t5 + z2 + z4) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[3] = (DCTELEM)(((t6 + z2 + z3) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));
        dataptr[1] = (DCTELEM)(((t7 + z1 + z4) + (((INT32)1) << ((13 - 2) - 1))) >> (13 - 2));

        dataptr += 8;
    }
}
