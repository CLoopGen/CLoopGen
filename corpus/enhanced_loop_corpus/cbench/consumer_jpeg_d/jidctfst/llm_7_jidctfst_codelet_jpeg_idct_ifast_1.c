#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef int DCTELEM;

typedef long INT32;

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



void loop() {
    // Introduce loop-carried dependency via accumulator to create RAW hazard
    DCTELEM acc = 0;
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;

        // Create artificial data dependency: current iteration depends on prior `acc`
        DCTELEM base_val = wsptr[0] + acc;  // RAW: use of previous iteration's acc

        if (((wsptr[1] + acc) | (wsptr[2] + acc) | (wsptr[3] + acc) |
             (wsptr[4] + acc) | (wsptr[5] + acc) | (wsptr[6] + acc) | (wsptr[7] + acc)) == 0) {
            JSAMPLE dcval = range_limit[((int)(base_val >> 5)) & 1023];
            for (int j = 0; j < 8; j++) {
                outptr[j] = dcval;
            }
            acc = base_val; // WAW: write used in next iteration
            wsptr += 8;
            continue;
        }

        tmp10 = (base_val + wsptr[4]);
        tmp11 = (base_val - wsptr[4]);
        tmp13 = (wsptr[2] + wsptr[6]);
        tmp12 = ((((DCTELEM)(wsptr[2] - wsptr[6]) * 362) >> 8)) - tmp13;

        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        z13 = wsptr[5] + wsptr[3];
        z10 = wsptr[5] - wsptr[3];
        z11 = wsptr[1] + wsptr[7];
        z12 = wsptr[1] - wsptr[7];

        tmp7 = z11 + z13;
        tmp11 = (((z11 - z13) * 362) >> 8);
        z5 = (((z10 + z12) * 473) >> 8);
        tmp10 = (((z12 * 277) >> 8)) - z5;
        tmp12 = (((z10 * (-669)) >> 8)) + z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        outptr[0] = range_limit[((int)((tmp0 + tmp7) >> 5)) & 1023];
        outptr[7] = range_limit[((int)((tmp0 - tmp7) >> 5)) & 1023];
        outptr[1] = range_limit[((int)((tmp1 + tmp6) >> 5)) & 1023];
        outptr[6] = range_limit[((int)((tmp1 - tmp6) >> 5)) & 1023];
        outptr[2] = range_limit[((int)((tmp2 + tmp5) >> 5)) & 1023];
        outptr[5] = range_limit[((int)((tmp2 - tmp5) >> 5)) & 1023];
        outptr[4] = range_limit[((int)((tmp3 + tmp4) >> 5)) & 1023];
        outptr[3] = range_limit[((int)((tmp3 - tmp4) >> 5)) & 1023];

        // Update accumulator for next iteration — creates loop-carried dependency
        acc = tmp0 + tmp1 + tmp2 + tmp3;

        wsptr += 8;
    }
}
