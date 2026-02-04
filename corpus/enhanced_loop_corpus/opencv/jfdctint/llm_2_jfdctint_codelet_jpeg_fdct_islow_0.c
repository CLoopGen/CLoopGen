#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef JLONG DCTELEM;

extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp3;
extern JLONG tmp4;
extern JLONG tmp5;
extern JLONG tmp6;
extern JLONG tmp7;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JLONG z5;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 8; ctr++) {
        DCTELEM *row_start = dataptr + (ctr * 8); // Row-wise consecutive access: now iterating forward with contiguous blocks

        tmp0 = row_start[0] + row_start[7];
        tmp7 = row_start[0] - row_start[7];
        tmp1 = row_start[1] + row_start[6];
        tmp6 = row_start[1] - row_start[6];
        tmp2 = row_start[2] + row_start[5];
        tmp5 = row_start[2] - row_start[5];
        tmp3 = row_start[3] + row_start[4];
        tmp4 = row_start[3] - row_start[4];

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        row_start[0] = (DCTELEM)((JLONG)((unsigned long)(tmp10 + tmp11) << 1));
        row_start[4] = (DCTELEM)((JLONG)((unsigned long)(tmp10 - tmp11) << 1));

        z1 = ((tmp12 + tmp13) * ((JLONG)4433));
        row_start[2] = (DCTELEM)(((z1 + ((tmp13) * ((JLONG)6270))) + (((JLONG)1) << (12))) >> 12);
        row_start[6] = (DCTELEM)(((z1 + ((tmp12) * (-((JLONG)15137)))) + (((JLONG)1) << 12)) >> 12);

        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = ((z3 + z4) * ((JLONG)9633));

        tmp4 = ((tmp4) * ((JLONG)2446));
        tmp5 = ((tmp5) * ((JLONG)16819));
        tmp6 = ((tmp6) * ((JLONG)25172));
        tmp7 = ((tmp7) * ((JLONG)12299));

        z1 = ((z1) * (-((JLONG)7373)));
        z2 = ((z2) * (-((JLONG)20995)));
        z3 = ((z3) * (-((JLONG)16069)));
        z4 = ((z4) * (-((JLONG)3196)));

        z3 += z5;
        z4 += z5;

        row_start[7] = (DCTELEM)(((tmp4 + z1 + z3) + (((JLONG)1) << 12)) >> 12);
        row_start[5] = (DCTELEM)(((tmp5 + z2 + z4) + (((JLONG)1) << 12)) >> 12);
        row_start[3] = (DCTELEM)(((tmp6 + z2 + z3) + (((JLONG)1) << 12)) >> 12);
        row_start[1] = (DCTELEM)(((tmp7 + z1 + z4) + (((JLONG)1) << 12)) >> 12);
    }
}
