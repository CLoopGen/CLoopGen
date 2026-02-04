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
    // Use indirect memory access via index mapping array to simulate irregular access
    static const int access_order[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Reordered access to wsptr elements
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;

        int base_idx = ctr * 8;
        int nonzero = 0;
        for (int j = 1; j < 8; j++) {
            int mapped_idx = base_idx + access_order[j]; // Indirect indexing
            if (wsptr[mapped_idx] != 0) {
                nonzero = 1;
                break;
            }
        }

        if (!nonzero) {
            int dc_index = base_idx + access_order[0];
            JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[dc_index]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
            for (int i = 0; i < 8; i++) {
                outptr[i] = dcval;
            }
            continue;
        }

        int idx2 = base_idx + 2, idx6 = base_idx + 6;
        z2 = (INT32)wsptr[idx2];
        z3 = (INT32)wsptr[idx6];
        z1 = (z2 + z3) * 4433;
        tmp2 = z1 - z3 * 15137;
        tmp3 = z1 + z2 * 6270;
        tmp0 = ((INT32)wsptr[base_idx + 0] + (INT32)wsptr[base_idx + 4]) << 13;
        tmp1 = ((INT32)wsptr[base_idx + 0] - (INT32)wsptr[base_idx + 4]) << 13;
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        // Access AC coefficients using shuffled order
        tmp0 = (INT32)wsptr[base_idx + 7];
        tmp1 = (INT32)wsptr[base_idx + 5];
        tmp2 = (INT32)wsptr[base_idx + 3];
        tmp3 = (INT32)wsptr[base_idx + 1];

        z1 = tmp0 + tmp3;
        z2 = tmp1 + tmp2;
        z3 = tmp0 + tmp2;
        z4 = tmp1 + tmp3;
        z5 = (z3 + z4) * 9633;

        tmp0 *= 2446;
        tmp1 *= 16819;
        tmp2 *= 25172;
        tmp3 *= 12299;

        z1 *= -7373;
        z2 *= -20995;
        z3 *= -16069;
        z4 *= -3196;

        z3 += z5;
        z4 += z5;

        tmp0 += z1 + z3;
        tmp1 += z2 + z4;
        tmp2 += z2 + z3;
        tmp3 += z1 + z4;

        INT32 out_shift = 18;
        INT32 rounder = 1 << 17;
        int limit_mask = 1023; // 255*4 + 3

        outptr[0] = range_limit[(int)((tmp10 + tmp3 + rounder) >> out_shift) & limit_mask];
        outptr[7] = range_limit[(int)((tmp10 - tmp3 + rounder) >> out_shift) & limit_mask];
        outptr[1] = range_limit[(int)((tmp11 + tmp2 + rounder) >> out_shift) & limit_mask];
        outptr[6] = range_limit[(int)((tmp11 - tmp2 + rounder) >> out_shift) & limit_mask];
        outptr[2] = range_limit[(int)((tmp12 + tmp1 + rounder) >> out_shift) & limit_mask];
        outptr[5] = range_limit[(int)((tmp12 - tmp1 + rounder) >> out_shift) & limit_mask];
        outptr[3] = range_limit[(int)((tmp13 + tmp0 + rounder) >> out_shift) & limit_mask];
        outptr[4] = range_limit[(int)((tmp13 - tmp0 + rounder) >> out_shift) & limit_mask];
    }
}
