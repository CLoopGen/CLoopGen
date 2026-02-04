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
    tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
    tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
    tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
    tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
    tmp5 = dataptr[8 * 2] - dataptr[8 * 5];
    tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
    tmp4 = dataptr[8 * 3] - dataptr[8 * 4];

    // Introduce temporary variables to break WAW and WAR dependencies
    JLONG t10 = tmp0 + tmp3;
    JLONG t13 = tmp0 - tmp3;
    JLONG t11 = tmp1 + tmp2;
    JLONG t12 = tmp1 - tmp2;

    // Use temporaries to eliminate write-after-write on dataptr
    DCTELEM out0 = (DCTELEM)(((t10 + t11) + (((JLONG)1) << ((1) - 1))) >> (1));
    DCTELEM out4 = (DCTELEM)(((t10 - t11) + (((JLONG)1) << ((1) - 1))) >> (1));

    z1 = ((t12 + t13) * (((JLONG)4433)));
    DCTELEM out2 = (DCTELEM)(((z1 + ((t13) * (((JLONG)6270)))) + (((JLONG)1) << ((13 + 1) - 1))) >> (13 + 1));
    DCTELEM out6 = (DCTELEM)(((z1 + ((t12) * (-((JLONG)15137)))) + (((JLONG)1) << ((13 + 1) - 1))) >> (13 + 1));

    JLONG tz1 = tmp4 + tmp7;
    JLONG tz2 = tmp5 + tmp6;
    JLONG tz3 = tmp4 + tmp6;
    JLONG tz4 = tmp5 + tmp7;
    JLONG tz5 = ((tz3 + tz4) * (((JLONG)9633)));

    JLONG ttmp4 = ((tmp4) * (((JLONG)2446)));
    JLONG ttmp5 = ((tmp5) * (((JLONG)16819)));
    JLONG ttmp6 = ((tmp6) * (((JLONG)25172)));
    JLONG ttmp7 = ((tmp7) * (((JLONG)12299)));
    JLONG tz1_scaled = ((tz1) * (-((JLONG)7373)));
    JLONG tz2_scaled = ((tz2) * (-((JLONG)20995)));
    JLONG tz3_scaled = ((tz3) * (-((JLONG)16069)));
    JLONG tz4_scaled = ((tz4) * (-((JLONG)3196)));

    tz3_scaled += tz5;
    tz4_scaled += tz5;

    DCTELEM out7 = (DCTELEM)(((ttmp4 + tz1_scaled + tz3_scaled) + (((JLONG)1) << ((13 + 1) - 1))) >> (13 + 1));
    DCTELEM out5 = (DCTELEM)(((ttmp5 + tz2_scaled + tz4_scaled) + (((JLONG)1) << ((13 + 1) - 1))) >> (13 + 1));
    DCTELEM out3 = (DCTELEM)(((ttmp6 + tz2_scaled + tz3_scaled) + (((JLONG)1) << ((13 + 1) - 1))) >> (13 + 1));
    DCTELEM out1 = (DCTELEM)(((ttmp7 + tz1_scaled + tz4_scaled) + (((JLONG)1) << ((13 + 1) - 1))) >> (13 + 1));

    // Single write-back phase to eliminate multiple write hazards
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
