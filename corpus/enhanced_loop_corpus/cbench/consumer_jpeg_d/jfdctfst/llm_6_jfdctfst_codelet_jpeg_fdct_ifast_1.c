#include <stdio.h>

#include <inttypes.h>

typedef int DCTELEM;

typedef long INT32;

extern DCTELEM tmp0;
extern DCTELEM tmp1;
extern DCTELEM tmp2;
extern DCTELEM tmp3;
extern DCTELEM tmp4;
extern DCTELEM tmp5;
extern DCTELEM tmp6;
extern DCTELEM tmp7;
extern DCTELEM tmp10;
extern DCTELEM tmp11;
extern DCTELEM tmp12;
extern DCTELEM tmp13;
extern DCTELEM z1;
extern DCTELEM z2;
extern DCTELEM z3;
extern DCTELEM z4;
extern DCTELEM z5;
extern DCTELEM z11;
extern DCTELEM z13;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        DCTELEM t0, t1, t2, t3, t4, t5, t6, t7;
        t0 = dataptr[8 * 0] + dataptr[8 * 7];
        t7 = dataptr[8 * 0] - dataptr[8 * 7];
        t1 = dataptr[8 * 1] + dataptr[8 * 6];
        t6 = dataptr[8 * 1] - dataptr[8 * 6];
        t2 = dataptr[8 * 2] + dataptr[8 * 5];
        t5 = dataptr[8 * 2] - dataptr[8 * 5];
        t3 = dataptr[8 * 3] + dataptr[8 * 4];
        t4 = dataptr[8 * 3] - dataptr[8 * 4];

        DCTELEM u10 = t0 + t3;
        DCTELEM u13 = t0 - t3;
        DCTELEM u11 = t1 + t2;
        DCTELEM u12 = t1 - t2;

        // Eliminate WAW dependency by using temporaries before final store
        DCTELEM out0 = u10 + u11;
        DCTELEM out4 = u10 - u11;

        z1 = ((DCTELEM)(((u12 + u13) * (((INT32)181))) >> 8));
        DCTELEM out2 = u13 + z1;
        DCTELEM out6 = u13 - z1;

        DCTELEM v10 = t4 + t5;
        DCTELEM v11 = t5 + t6;
        DCTELEM v12 = t6 + t7;
        z5 = ((DCTELEM)(((v10 - v12) * (((INT32)98))) >> 8));
        z2 = ((DCTELEM)(((v10) * (((INT32)139))) >> 8)) + z5;
        z4 = ((DCTELEM)(((v12) * (((INT32)334))) >> 8)) + z5;
        z3 = ((DCTELEM)(((v11) * (((INT32)181))) >> 8));
        z11 = t7 + z3;
        z13 = t7 - z3;

        DCTELEM out5 = z13 + z2;
        DCTELEM out3 = z13 - z2;
        DCTELEM out1 = z11 + z4;
        DCTELEM out7 = z11 - z4;

        // Final stores with no intra-loop WAR/WAW on tmp* variables
        dataptr[8 * 0] = out0;
        dataptr[8 * 4] = out4;
        dataptr[8 * 2] = out2;
        dataptr[8 * 6] = out6;
        dataptr[8 * 5] = out5;
        dataptr[8 * 3] = out3;
        dataptr[8 * 1] = out1;
        dataptr[8 * 7] = out7;

        dataptr++;
    }
}
