#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 6; ctr++) {
    outptr = output_buf[ctr] + output_col;

    // Introduce temporary variables to break WAW and WAR hazards
    JLONG t_wsptr0 = (JLONG)wsptr[0];
    JLONG t_wsptr2 = (JLONG)wsptr[2];
    JLONG t_wsptr4 = (JLONG)wsptr[4];
    JLONG t_wsptr1 = (JLONG)wsptr[1];
    JLONG t_wsptr3 = (JLONG)wsptr[3];
    JLONG t_wsptr5 = (JLONG)wsptr[5];

    // Reorder independent computations to reduce loop-carried dependencies
    JLONG local_tmp0 = (t_wsptr0 + (((JLONG)1) << (1 + 2))) << 13;
    JLONG local_tmp2 = t_wsptr4;
    JLONG local_tmp10 = local_tmp2 * (JLONG)(0.70710678100000002 * ((JLONG)1 << 13) + 0.5);
    JLONG stage1_plus = local_tmp0 + local_tmp10;
    JLONG stage1_minus = local_tmp0 - 2 * local_tmp10;

    JLONG coeff_12247 = (JLONG)(1.224744871 * ((JLONG)1 << 13) + 0.5);
    JLONG tmp_val = t_wsptr2 * coeff_12247;
    JLONG final_tmp10 = stage1_plus + tmp_val;
    JLONG final_tmp12 = stage1_plus - tmp_val;

    JLONG sum_z1z3 = t_wsptr1 + t_wsptr5;
    JLONG diff_z3z2 = t_wsptr5 - t_wsptr3;
    JLONG sum_z1z2 = t_wsptr1 + t_wsptr3;
    JLONG expr_z1z2z3 = t_wsptr1 - t_wsptr3 - t_wsptr5;

    JLONG base_term = (sum_z1z3) * (JLONG)(0.366025404 * ((JLONG)1 << 13) + 0.5);
    JLONG ftmp0 = base_term + ((JLONG)((unsigned long)sum_z1z2 << 13));
    JLONG ftmp2 = base_term + ((JLONG)((unsigned long)diff_z3z2 << 13));
    JLONG ftmp1 = ((JLONG)((unsigned long)expr_z1z2z3 << 13));

    int shift = 13 + 1 + 3;
    unsigned int mask = (255 * 4 + 3);

    // Store results with explicit ordering, reducing write-after-write on outptr
    outptr[0] = range_limit[(int)((final_tmp10 + ftmp0) >> shift) & mask];
    outptr[5] = range_limit[(int)((final_tmp10 - ftmp0) >> shift) & mask];
    outptr[1] = range_limit[(int)((stage1_minus + ftmp1) >> shift) & mask];
    outptr[4] = range_limit[(int)((stage1_minus - ftmp1) >> shift) & mask];
    outptr[2] = range_limit[(int)((final_tmp12 + ftmp2) >> shift) & mask];
    outptr[3] = range_limit[(int)((final_tmp12 - ftmp2) >> shift) & mask];

    wsptr += 6;
}

}
