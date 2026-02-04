#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp4;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        // Reorder independent operations to modify data dependency graph
        // Load all required values first to minimize anti-dependence

        DCTELEM d0 = dataptr[8 * 0], d1 = dataptr[8 * 1], d2 = dataptr[8 * 2];
        DCTELEM d3 = dataptr[8 * 3], d4 = dataptr[8 * 4], d5 = dataptr[8 * 5];
        DCTELEM d6 = dataptr[8 * 6], d7 = dataptr[8 * 7];
        DCTELEM w1 = wsptr[8 * 1], w0 = wsptr[8 * 0];

        // Eliminate some loop-carried dependencies by fusing symmetric computations
        tmp0 = d0 + w1;
        tmp1 = d1 + w0;
        tmp12 = d2 + d7;
        tmp3 = d3 + d6;
        tmp4 = d4 + d5;

        tmp10 = tmp0 + tmp4;
        tmp13 = tmp0 - tmp4;
        tmp11 = tmp1 + tmp3;
        tmp14 = tmp1 - tmp3;

        // Rearranged subtraction phase with immediate use to increase locality
        INT32 s0 = d0 - w1;
        INT32 s1 = d1 - w0;
        INT32 s2 = d2 - d7;
        INT32 s3 = d3 - d6;
        INT32 s4 = d4 - d5;

        // Combine multiplications into larger expressions to reduce intermediate storage (WAW reduction)
        INT32 factor = ((INT32)(1.28 * ((INT32)1 << 13) + 0.5));
        INT32 factor2 = ((INT32)(1.464477191 * ((INT32)1 << 13) + 0.5));
        INT32 factor3 = ((INT32)(0.559380511 * ((INT32)1 << 13) + 0.5));
        INT32 offset = (INT32)1 << 14;

        dataptr[8 * 0] = (DCTELEM)((((tmp10 + tmp11 + tmp12) * factor) + offset) >> 15);
        dataptr[8 * 4] = (DCTELEM)((((tmp10 - (tmp12 << 1)) * factor2 - 
                                   (tmp11 - (tmp12 << 1)) * factor3) + offset) >> 15);

        INT32 base = ((tmp13 + tmp14) * ((INT32)(1.064004961 * (1 << 13) + 0.5)));
        INT32 corr1 = ((tmp13) * ((INT32)(0.65759123 * (1 << 13) + 0.5)));
        INT32 corr2 = ((tmp14) * ((INT32)(2.785601151 * (1 << 13) + 0.5)));

        dataptr[8 * 2] = (DCTELEM)(((base + corr1 + offset) >> 15));
        dataptr[8 * 6] = (DCTELEM)(((base - corr2 + offset) >> 15));

        tmp10 = s0 + s4;
        tmp11 = s1 - s3;

        dataptr[8 * 5] = (DCTELEM)((((tmp10 - tmp11 - s2) * factor) + offset) >> 15);
        INT32 scaled_s2 = s2 * factor;

        dataptr[8 * 1] = (DCTELEM)((((s0 * ((INT32)(1.787906876 * (1 << 13) + 0.5))) +
                                   (s1 * ((INT32)(1.612894094 * (1 << 13) + 0.5))) +
                                   scaled_s2 +
                                   (s3 * ((INT32)(0.821810588 * (1 << 13) + 0.5))) +
                                   (s4 * ((INT32)(0.28317663 * (1 << 13) + 0.5)))) + offset) >> 15);

        INT32 diff_term = (s0 - s4) * ((INT32)(1.217352341 * (1 << 13) + 0.5));
        INT32 sum_term = (s1 + s3) * ((INT32)(0.752365123 * (1 << 13) + 0.5));
        INT32 cross = (tmp10 + tmp11) * ((INT32)(0.395541753 * (1 << 13) + 0.5)) +
                      (tmp11 * ((INT32)(0.64 * (1 << 13) + 0.5))) - scaled_s2;

        dataptr[8 * 3] = (DCTELEM)(((diff_term - sum_term + cross + offset) >> 15));
        dataptr[8 * 7] = (DCTELEM)(((diff_term - sum_term - cross + offset) >> 15));

        // Update pointers at the end — maintains same semantics
        dataptr++;
        wsptr++;
    }
}
