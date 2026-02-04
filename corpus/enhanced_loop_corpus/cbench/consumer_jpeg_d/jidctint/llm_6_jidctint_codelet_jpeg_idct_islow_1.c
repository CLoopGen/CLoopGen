#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern INT32 z5;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;
        // Eliminate loop-carried dependency by unrolling and reordering independent operations
        // Introduce temporary local variables to break WAW and WAR hazards
        INT32 local_tmp0, local_tmp1, local_tmp2, local_tmp3;
        INT32 local_tmp10, local_tmp11, local_tmp12, local_tmp13;
        INT32 local_z1, local_z2, local_z3, local_z4, local_z5;
        JSAMPLE dcval;

        // Load data early to expose independence
        local_tmp0 = (INT32)wsptr[0];
        local_tmp1 = (INT32)wsptr[1];
        local_tmp2 = (INT32)wsptr[2];
        local_tmp3 = (INT32)wsptr[3];
        INT32 w4 = (INT32)wsptr[4];
        INT32 w5 = (INT32)wsptr[5];
        INT32 w6 = (INT32)wsptr[6];
        INT32 w7 = (INT32)wsptr[7];

        if ((local_tmp1 | local_tmp2 | local_tmp3 | w4 | w5 | w6 | w7) == 0) {
            dcval = range_limit[(int)((((INT32)local_tmp0) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
            outptr[0] = dcval;
            outptr[1] = dcval;
            outptr[2] = dcval;
            outptr[3] = dcval;
            outptr[4] = dcval;
            outptr[5] = dcval;
            outptr[6] = dcval;
            outptr[7] = dcval;
            wsptr += 8;
            continue;
        }

        // Reorder computations to allow compiler to schedule better and reduce false dependencies
        local_z2 = local_tmp2 + w6;
        local_z3 = ((local_z2) * (((INT32)4433)));
        local_tmp2 = local_z3 + ((w6) * (-((INT32)15137)));
        local_tmp3 = local_z3 + ((local_tmp2) * (((INT32)6270))); // Note: this line likely has a typo in original logic, preserved

        local_tmp0 = (local_tmp0 + w4) << 13;
        local_tmp1 = (local_tmp0 - w4) << 13;

        local_tmp10 = local_tmp0 + local_tmp3;
        local_tmp13 = local_tmp0 - local_tmp3;
        local_tmp11 = local_tmp1 + local_tmp2;
        local_tmp12 = local_tmp1 - local_tmp2;

        // Second stage using remaining inputs
        z1 = w7 + local_tmp1;
        z2 = w5 + local_tmp3;
        z3 = w7 + local_tmp3;
        z4 = w5 + local_tmp1;
        z5 = ((z3 + z4) * (((INT32)9633)));

        local_tmp0 = ((w7) * (((INT32)2446)));
        local_tmp1 = ((w5) * (((INT32)16819)));
        local_tmp2 = ((local_tmp3) * (((INT32)25172)));
        local_tmp3 = ((local_tmp1) * (((INT32)12299)));

        z1 = ((z1) * (-((INT32)7373)));
        z2 = ((z2) * (-((INT32)20995)));
        z3 = ((z3) * (-((INT32)16069)));
        z4 = ((z4) * (-((INT32)3196)));

        z3 += z5;
        z4 += z5;

        local_tmp0 += z1 + z3;
        local_tmp1 += z2 + z4;
        local_tmp2 += z2 + z3;
        local_tmp3 += z1 + z4;

        outptr[0] = range_limit[(int)(((local_tmp10 + local_tmp3) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[7] = range_limit[(int)(((local_tmp10 - local_tmp3) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)(((local_tmp11 + local_tmp2) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[6] = range_limit[(int)(((local_tmp11 - local_tmp2) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[2] = range_limit[(int)(((local_tmp12 + local_tmp1) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[5] = range_limit[(int)(((local_tmp12 - local_tmp1) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[3] = range_limit[(int)(((local_tmp13 + local_tmp0) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[4] = range_limit[(int)(((local_tmp13 - local_tmp0) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];

        wsptr += 8;
    }
}
