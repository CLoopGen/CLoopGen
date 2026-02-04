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



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    // Eliminate some intermediate reuse to remove WAW and WAR hazards
    // Fuse computations and reduce live ranges of temporaries

    JLONG d0 = dataptr[0], d1 = dataptr[1], d2 = dataptr[2], d3 = dataptr[3];
    JLONG d4 = dataptr[4], d5 = dataptr[5], d6 = dataptr[6], d7 = dataptr[7];

    JLONG sum07 = d0 + d7, diff07 = d0 - d7;
    JLONG sum16 = d1 + d6, diff16 = d1 - d6;
    JLONG sum25 = d2 + d5, diff25 = d2 - d5;
    JLONG sum34 = d3 + d4, diff34 = d3 - d4;

    JLONG comboA = sum07 + sum34;
    JLONG comboB = sum16 + sum25;
    JLONG comboC = sum07 - sum34;
    JLONG comboD = sum16 - sum25;

    // Compute results directly without reusing tmp12, tmp13 later
    dataptr[0] = (DCTELEM)((JLONG)((unsigned long)(comboA + comboB) << 1));
    dataptr[4] = (DCTELEM)((JLONG)((unsigned long)(comboA - comboB) << 1));

    // Use immediate expressions to eliminate loop-carried dependency via z1 reuse
    JLONG partial_z1 = ((comboD + comboC) * ((JLONG)4433));
    dataptr[2] = (DCTELEM)(((partial_z1 + (comboC * ((JLONG)6270))) + (((JLONG)1) << 11)) >> 12);
    dataptr[6] = (DCTELEM)(((partial_z1 + (comboD * (-((JLONG)15137)))) + (((JLONG)1) << 11)) >> 12);

    // Restructure second half with direct arithmetic to avoid write-after-write on z1-z4
    JLONG v1 = (diff34 + diff07) * (-7373LL);
    JLONG v2 = (diff25 + diff16) * (-20995LL);
    JLONG v3 = (diff34 + diff16) * (-16069LL);
    JLONG v4 = (diff25 + diff07) * (-3196LL);
    JLONG v5 = ((diff34 + diff16) + (diff25 + diff07)) * 9633LL;

    JLONG w4 = diff34 * 2446LL;
    JLONG w5 = diff25 * 16819LL;
    JLONG w6 = diff16 * 25172LL;
    JLONG w7 = diff07 * 12299LL;

    v3 += v5;
    v4 += v5;

    dataptr[7] = (DCTELEM)(((w4 + v1 + v3) + (((JLONG)1) << 11)) >> 12);
    dataptr[5] = (DCTELEM)(((w5 + v2 + v4) + (((JLONG)1) << 11)) >> 12);
    dataptr[3] = (DCTELEM)(((w6 + v2 + v3) + (((JLONG)1) << 11)) >> 12);
    dataptr[1] = (DCTELEM)(((w7 + v1 + v4) + (((JLONG)1) << 11)) >> 12);

    dataptr += 8;
}
}
