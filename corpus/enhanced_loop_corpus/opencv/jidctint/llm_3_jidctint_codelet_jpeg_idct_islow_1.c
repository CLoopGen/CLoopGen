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
extern JLONG tmp3;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG tmp13;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JLONG z5;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int access_pattern[8] = {0, 4, 2, 6, 1, 5, 3, 7}; // Indirect access via index remapping
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;
        int base_idx = ctr * 8;
        int idx1 = base_idx + access_pattern[1];
        int idx2 = base_idx + access_pattern[2];
        int idx3 = base_idx + access_pattern[3];
        int idx4 = base_idx + access_pattern[4];
        int idx5 = base_idx + access_pattern[5];
        int idx6 = base_idx + access_pattern[6];
        int idx7 = base_idx + access_pattern[7];
        if (wsptr[idx1] == 0 && wsptr[idx2] == 0 && wsptr[idx3] == 0 &&
            wsptr[idx4] == 0 && wsptr[idx5] == 0 && wsptr[idx6] == 0 && wsptr[idx7] == 0) {
            int dc_idx = base_idx + access_pattern[0];
            JSAMPLE dcval = range_limit[(int)((((JLONG)wsptr[dc_idx]) + (((JLONG)1) << ((1 + 3) - 1))) >> (1 + 3)) & (255 * 4 + 3)];
            for (int i = 0; i < 8; i++) {
                outptr[i] = dcval;
            }
            continue;
        }
        z2 = (JLONG)wsptr[base_idx + access_pattern[2]];
        z3 = (JLONG)wsptr[base_idx + access_pattern[6]];
        z1 = ((z2 + z3) * (((JLONG)4433)));
        tmp2 = z1 + ((z3) * (-((JLONG)15137)));
        tmp3 = z1 + ((z2) * (((JLONG)6270)));
        tmp0 = ((JLONG)((unsigned long)((JLONG)wsptr[base_idx + access_pattern[0]] + (JLONG)wsptr[base_idx + access_pattern[4]]) << (13)));
        tmp1 = ((JLONG)((unsigned long)((JLONG)wsptr[base_idx + access_pattern[0]] - (JLONG)wsptr[base_idx + access_pattern[4]]) << (13)));
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp0 = (JLONG)wsptr[base_idx + access_pattern[7]];
        tmp1 = (JLONG)wsptr[base_idx + access_pattern[5]];
        tmp2 = (JLONG)wsptr[base_idx + access_pattern[3]];
        tmp3 = (JLONG)wsptr[base_idx + access_pattern[1]];
        z1 = tmp0 + tmp3;
        z2 = tmp1 + tmp2;
        z3 = tmp0 + tmp2;
        z4 = tmp1 + tmp3;
        z5 = ((z3 + z4) * (((JLONG)9633)));
        tmp0 = ((tmp0) * (((JLONG)2446)));
        tmp1 = ((tmp1) * (((JLONG)16819)));
        tmp2 = ((tmp2) * (((JLONG)25172)));
        tmp3 = ((tmp3) * (((JLONG)12299)));
        z1 = ((z1) * (-((JLONG)7373)));
        z2 = ((z2) * (-((JLONG)20995)));
        z3 = ((z3) * (-((JLONG)16069)));
        z4 = ((z4) * (-((JLONG)3196)));
        z3 += z5;
        z4 += z5;
        tmp0 += z1 + z3;
        tmp1 += z2 + z4;
        tmp2 += z2 + z3;
        tmp3 += z1 + z4;
        outptr[0] = range_limit[(int)(((tmp10 + tmp3) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[7] = range_limit[(int)(((tmp10 - tmp3) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)(((tmp11 + tmp2) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[6] = range_limit[(int)(((tmp11 - tmp2) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[2] = range_limit[(int)(((tmp12 + tmp1) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[5] = range_limit[(int)(((tmp12 - tmp1) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[3] = range_limit[(int)(((tmp13 + tmp0) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
        outptr[4] = range_limit[(int)(((tmp13 - tmp0) + (((JLONG)1) << ((13 + 1 + 3) - 1))) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    }
}
