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
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
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
for (ctr = 0; ctr < 9; ctr++) {
    outptr = output_buf[ctr] + output_col;

    // Introduce temporal reuse: split computation into two phases with intermediate storage
    INT32 local_tmp[8]; // Local buffer to break global dependencies

    // First, load and scale all wsptr values upfront to remove RAW hazards
    for (int i = 0; i < 8; i++) {
        local_tmp[i] = (INT32)wsptr[i];
    }

    tmp0 = local_tmp[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    tmp0 <<= 13;

    z1 = local_tmp[2];
    z2 = local_tmp[4];
    z3 = local_tmp[6];

    tmp3 = (z3 * ((INT32)(0.707106781 * (1 << 13) + 0.5)));
    tmp1 = tmp0 + tmp3;
    tmp2 = tmp0 - 2 * tmp3;

    tmp0 = (z1 - z2) * ((INT32)(0.707106781 * (1 << 13) + 0.5));
    tmp11 = tmp2 + tmp0;
    tmp14 = tmp2 - 2 * tmp0;

    tmp0 = (z1 + z2) * ((INT32)(1.328926049 * (1 << 13) + 0.5));
    tmp2 = z1 * ((INT32)(1.083350441 * (1 << 13) + 0.5));
    tmp3 = z2 * ((INT32)(0.245575608 * (1 << 13) + 0.5));
    tmp10 = tmp1 + tmp0 - tmp3;
    tmp12 = tmp1 - tmp0 + tmp2;
    tmp13 = tmp1 - tmp2 + tmp3;

    z1 = local_tmp[1];
    z2 = local_tmp[3];
    z3 = local_tmp[5];
    z4 = local_tmp[7];

    INT32 neg_z2_scaled = -(z2 * ((INT32)(1.224744871 * (1 << 13) + 0.5)));

    tmp2 = (z1 + z3) * ((INT32)(0.909038955 * (1 << 13) + 0.5));
    tmp3 = (z1 + z4) * ((INT32)(0.483689525 * (1 << 13) + 0.5));
    tmp0 = tmp2 + tmp3 + neg_z2_scaled;

    tmp1 = (z3 - z4) * ((INT32)(1.392728481 * (1 << 13) + 0.5));
    tmp2 = tmp2 + neg_z2_scaled - tmp1;
    tmp3 = tmp3 + neg_z2_scaled + tmp1;

    tmp1 = (z1 - z3 - z4) * ((INT32)(1.224744871 * (1 << 13) + 0.5));

    // Store results with explicit ordering to eliminate WAW on outptr
    outptr[4] = range_limit[(int)(tmp14 >> (18)) & 1023];
    outptr[0] = range_limit[(int)((tmp10 + tmp0) >> 18) & 1023];
    outptr[8] = range_limit[(int)((tmp10 - tmp0) >> 18) & 1023];
    outptr[1] = range_limit[(int)((tmp11 + tmp1) >> 18) & 1023];
    outptr[7] = range_limit[(int)((tmp11 - tmp1) >> 18) & 1023];
    outptr[2] = range_limit[(int)((tmp12 + tmp2) >> 18) & 1023];
    outptr[6] = range_limit[(int)((tmp12 - tmp2) >> 18) & 1023];
    outptr[3] = range_limit[(int)((tmp13 + tmp3) >> 18) & 1023];
    outptr[5] = range_limit[(int)((tmp13 - tmp3) >> 18) & 1023];

    wsptr += 8;
}
}
