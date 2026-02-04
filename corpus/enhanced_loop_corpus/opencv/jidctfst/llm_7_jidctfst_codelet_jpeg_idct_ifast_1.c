#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

typedef JLONG DCTELEM;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern DCTELEM tmp0;
extern DCTELEM tmp1;
extern DCTELEM tmp2;
extern DCTELEM tmp3;
extern DCTELEM tmp4;
extern DCTELEM tmp5;
extern DCTELEM tmp6;
extern DCTELEM tmp7;
extern DCTELEM tmp10;
extern DCTELEM tmp11;
extern DCTELEM tmp12;
extern DCTELEM tmp13;
extern DCTELEM z5;
extern DCTELEM z10;
extern DCTELEM z11;
extern DCTELEM z12;
extern DCTELEM z13;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
DCTELEM local_tmp[8][8]; // Introduce local storage to break direct WAW and WAR dependencies across iterations
for (ctr = 0; ctr < 8; ctr++) {
    outptr = output_buf[ctr] + output_col;

    // Remove loop-carried dependency by pre-loading all data
    DCTELEM w0 = wsptr[0], w1 = wsptr[1], w2 = wsptr[2], w3 = wsptr[3];
    DCTELEM w4 = wsptr[4], w5 = wsptr[5], w6 = wsptr[6], w7 = wsptr[7];

    if (w1 == 0 && w2 == 0 && w3 == 0 && w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0) {
        JSAMPLE dcval = range_limit[(w0 >> 4) & 1023];
        for (int i = 0; i < 8; i++) {
            outptr[i] = dcval;
        }
        wsptr += 8;
        continue;
    }

    // Restructure arithmetic to eliminate intermediate variable reuse (break WAW)
    DCTELEM a = w0 + w4;
    DCTELEM b = w0 - w4;
    DCTELEM c = w2 + w6;
    DCTELEM d = (((w2 - w6) * 362LL) >> 8) - c;

    local_tmp[ctr][0] = a + c;
    local_tmp[ctr][3] = a - c;
    local_tmp[ctr][1] = b + d;
    local_tmp[ctr][2] = b - d;

    DCTELEM e = w5 + w3;
    DCTELEM f = w5 - w3;
    DCTELEM g = w1 + w7;
    DCTELEM h = w1 - w7;

    local_tmp[ctr][7] = g + e;
    DCTELEM t11 = ((g - e) * 362LL) >> 8;
    DCTELEM z5_local = ((f + h) * 473LL) >> 8;
    DCTELEM t10_local = ((h * 277LL) >> 8) - z5_local;
    DCTELEM t12_local = ((f * (-669LL)) >> 8) + z5_local;
    DCTELEM t6_local = t12_local - local_tmp[ctr][7];
    DCTELEM t5_local = t11 - t6_local;
    DCTELEM t4_local = t10_local + t5_local;

    local_tmp[ctr][6] = t6_local;
    local_tmp[ctr][5] = t5_local;
    local_tmp[ctr][4] = t4_local;

    // Final store with reduced data hazards via local_tmp indexing per iteration
    outptr[0] = range_limit[((local_tmp[ctr][0] + local_tmp[ctr][7]) >> 4) & 1023];
    outptr[7] = range_limit[((local_tmp[ctr][0] - local_tmp[ctr][7]) >> 4) & 1023];
    outptr[1] = range_limit[((local_tmp[ctr][1] + local_tmp[ctr][6]) >> 4) & 1023];
    outptr[6] = range_limit[((local_tmp[ctr][1] - local_tmp[ctr][6]) >> 4) & 1023];
    outptr[2] = range_limit[((local_tmp[ctr][2] + local_tmp[ctr][5]) >> 4) & 1023];
    outptr[5] = range_limit[((local_tmp[ctr][2] - local_tmp[ctr][5]) >> 4) & 1023];
    outptr[4] = range_limit[((local_tmp[ctr][3] + local_tmp[ctr][4]) >> 4) & 1023];
    outptr[3] = range_limit[((local_tmp[ctr][3] - local_tmp[ctr][4]) >> 4) & 1023];

    wsptr += 8;
}
}
