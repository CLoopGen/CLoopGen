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
    int access_pattern[8] = {0, 4, 2, 6, 1, 5, 3, 7}; // Reordered (bit-reversed or indirect) access pattern
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;
        int base_idx = ctr * 8;
        int total_or = 0;
        for (int i = 1; i < 8; i++) {
            total_or |= wsptr[base_idx + access_pattern[i]];
        }
        if (total_or == 0) {
            JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[base_idx + access_pattern[0]]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
            for (int i = 0; i < 8; i++) {
                outptr[i] = dcval;
            }
            continue;
        }
        z2 = (INT32)wsptr[base_idx + access_pattern[2]];
        z3 = (INT32)wsptr[base_idx + access_pattern[6]];
        z1 = ((z2 + z3) * (((INT32)4433)));
        tmp2 = z1 + ((z3) * (-((INT32)15137)));
        tmp3 = z1 + ((z2) * (((INT32)6270)));
        tmp0 = ((INT32)wsptr[base_idx + access_pattern[0]] + (INT32)wsptr[base_idx + access_pattern[4]]) << 13;
        tmp1 = ((INT32)wsptr[base_idx + access_pattern[0]] - (INT32)wsptr[base_idx + access_pattern[4]]) << 13;
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp0 = (INT32)wsptr[base_idx + access_pattern[7]];
        tmp1 = (INT32)wsptr[base_idx + access_pattern[5]];
        tmp2 = (INT32)wsptr[base_idx + access_pattern[3]];
        tmp3 = (INT32)wsptr[base_idx + access_pattern[1]];
        z1 = tmp0 + tmp3;
        z2 = tmp1 + tmp2;
        z3 = tmp0 + tmp2;
        z4 = tmp1 + tmp3;
        z5 = ((z3 + z4) * (((INT32)9633)));
        tmp0 = ((tmp0) * (((INT32)2446)));
        tmp1 = ((tmp1) * (((INT32)16819)));
        tmp2 = ((tmp2) * (((INT32)25172)));
        tmp3 = ((tmp3) * (((INT32)12299)));
        z1 = ((z1) * (-((INT32)7373)));
        z2 = ((z2) * (-((INT32)20995)));
        z3 = ((z3) * (-((INT32)16069)));
        z4 = ((z4) * (-((INT32)3196)));
        z3 += z5;
        z4 += z5;
        tmp0 += z1 + z3;
        tmp1 += z2 + z4;
        tmp2 += z2 + z3;
        tmp3 += z1 + z4;
        outptr[0] = range_limit[(int)(((tmp10 + tmp3) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[7] = range_limit[(int)(((tmp10 - tmp3) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)(((tmp11 + tmp2) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[6] = range_limit[(int)(((tmp11 - tmp2) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[2] = range_limit[(int)(((tmp12 + tmp1) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[5] = range_limit[(int)(((tmp12 - tmp1) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[3] = range_limit[(int)(((tmp13 + tmp0) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
        outptr[4] = range_limit[(int)(((tmp13 - tmp0) + (((INT32)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3)) & (255 * 4 + 3)];
    }
}
