#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 5; ctr++) {
    outptr = output_buf[ctr] + output_col;

    // Introduce new temporary variables to break some WAW and WAR hazards
    INT32 local_z3 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    local_z3 <<= 13;
    INT32 local_z4 = (INT32)wsptr[4];
    INT32 local_z1 = ((local_z4) * (((INT32)((1.1441228059999999) * (((INT32)1) << 13) + 0.5))));
    INT32 local_z2 = ((local_z4) * (((INT32)((0.437016024) * (((INT32)1) << 13) + 0.5))));

    INT32 stage1_tmp10 = local_z3 + local_z1;
    INT32 stage1_tmp11 = local_z3 - local_z2;
    INT32 stage1_tmp22 = local_z3 - ((local_z1 - local_z2) << 1);

    local_z2 = (INT32)wsptr[2];
    local_z1 = (INT32)wsptr[6];
    INT32 sum_z2_z1 = local_z2 + local_z1;
    INT32 coeff_term = ((sum_z2_z1) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
    INT32 stage2_tmp12 = coeff_term + ((local_z2) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))));
    INT32 stage2_tmp13 = coeff_term - ((local_z1) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))));

    INT32 tmp20 = stage1_tmp10 + stage2_tmp12;
    INT32 tmp24 = stage1_tmp10 - stage2_tmp12;
    INT32 tmp21 = stage1_tmp11 + stage2_tmp13;
    INT32 tmp23 = stage1_tmp11 - stage2_tmp13;

    // Reorder independent computations to modify data flow
    INT32 w1 = (INT32)wsptr[1];
    INT32 w3 = (INT32)wsptr[3];
    INT32 w5 = (INT32)wsptr[5];
    INT32 w7 = (INT32)wsptr[7];

    INT32 t11 = w3 + w7;
    INT32 t13 = w3 - w7;
    INT32 t12 = ((t13) * (((INT32)((0.30901699399999999) * (((INT32)1) << 13) + 0.5))));
    INT32 tz2 = ((t11) * (((INT32)((0.95105651599999996) * (((INT32)1) << 13) + 0.5))));
    INT32 tz4 = ((w5) << 13) + t12;

    INT32 final_tmp10 = ((w1) * (((INT32)((1.3968022470000001) * (((INT32)1) << 13) + 0.5)))) + tz2 + tz4;
    INT32 final_tmp14 = ((w1) * (((INT32)((0.22123174200000001) * (((INT32)1) << 13) + 0.5)))) - tz2 + tz4;

    tz2 = ((t11) * (((INT32)((0.58778525199999998) * (((INT32)1) << 13) + 0.5))));
    tz4 = (w5 << 13) - t12 - (t13 << (13 - 1));
    INT32 delayed_tmp12 = ((w1 - t13) << 13) - (w5 << 13);
    INT32 final_tmp11 = ((w1) * (((INT32)((1.2600735110000001) * (((INT32)1) << 13) + 0.5)))) - tz2 - tz4;
    INT32 final_tmp13 = ((w1) * (((INT32)((0.64203952200000003) * (((INT32)1) << 13) + 0.5)))) - tz2 + tz4;

    // Store results with modified dependency chain: all temps are now locally scoped
    outptr[0] = range_limit[(int)((tmp20 + final_tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[9] = range_limit[(int)((tmp20 - final_tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)((tmp21 + final_tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[8] = range_limit[(int)((tmp21 - final_tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((stage1_tmp22 + delayed_tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[7] = range_limit[(int)((stage1_tmp22 - delayed_tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[3] = range_limit[(int)((tmp23 + final_tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[6] = range_limit[(int)((tmp23 - final_tmp13) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[4] = range_limit[(int)((tmp24 + final_tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[5] = range_limit[(int)((tmp24 - final_tmp14) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];

    wsptr += 8;
}

}
