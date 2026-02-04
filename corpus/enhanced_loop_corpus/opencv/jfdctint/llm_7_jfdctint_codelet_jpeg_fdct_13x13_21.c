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
extern INT32 tmp5;
extern INT32 tmp6;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 z1;
extern INT32 z2;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    // Introduce artificial loop-carried dependency via reuse of previous iteration's value
    static INT32 prev_tmp0 = 0; // Carries value from one iteration to next

    tmp10 = dataptr[8 * 0] - wsptr[8 * 4];
    tmp11 = dataptr[8 * 1] - wsptr[8 * 3];
    tmp12 = dataptr[8 * 2] - wsptr[8 * 2];
    tmp13 = dataptr[8 * 3] - wsptr[8 * 1];
    tmp14 = dataptr[8 * 4] - wsptr[8 * 0];
    tmp15 = dataptr[8 * 5] - dataptr[8 * 7];

    // Modified: use prev_tmp0 to create RAW and loop-carried dependence
    tmp0 = (dataptr[8 * 0] + wsptr[8 * 4]) + (prev_tmp0 >> 4); // RAW with prev iteration
    tmp1 = dataptr[8 * 1] + wsptr[8 * 3];
    tmp2 = dataptr[8 * 2] + wsptr[8 * 2];
    tmp3 = dataptr[8 * 3] + wsptr[8 * 1];
    tmp4 = dataptr[8 * 4] + wsptr[8 * 0];
    tmp5 = dataptr[8 * 5] + dataptr[8 * 7];
    tmp6 = dataptr[8 * 6];

    // Break some WAW hazards by merging calculations earlier
    INT32 total = tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5 + tmp6;
    INT32 factor = ((INT32)((0.75739645) * (((INT32)1) << 13) + 0.5));
    dataptr[8 * 0] = (DCTELEM)((((total * factor) + ((INT32)1 << (13))) >> (14)));

    // Modify update order to delay writes and increase live range (introduce WAR hazard artificially)
    tmp6 += tmp6;
    tmp0 -= tmp6;
    tmp1 -= tmp6;
    tmp2 -= tmp6;
    tmp3 -= tmp6;
    tmp4 -= tmp6;
    tmp5 -= tmp6;

    // Use compound expressions to reduce intermediate writes (eliminate some tmpX WAW)
    INT32 term1 = (tmp0 - tmp2) * ((INT32)(0.875087516 * (1<<13) + 0.5));
    INT32 term2 = (tmp3 - tmp4) * ((INT32)(0.330085509 * (1<<13) + 0.5));
    INT32 term3 = (tmp1 - tmp5) * ((INT32)(0.239678205 * (1<<13) + 0.5));
    z1 = term1 - term2 - term3;

    INT32 sum_even = tmp0 + tmp2;
    INT32 sum_odd1 = tmp3 + tmp4;
    INT32 sum_odd2 = tmp1 + tmp5;
    z2 = (sum_even * ((INT32)(0.073342435 * (1<<13) + 0.5)))
       - (sum_odd1 * ((INT32)(0.709910013 * (1<<13) + 0.5)))
       + (sum_odd2 * ((INT32)(0.368787494 * (1<<13) + 0.5)));

    dataptr[8 * 4] = (DCTELEM)(((z1 + z2) + (1 << 13)) >> 14);
    dataptr[8 * 6] = (DCTELEM)(((z1 - z2) + (1 << 13)) >> 14);

    // Rearranged to use values before they're overwritten, increasing register pressure
    INT32 t10_11 = tmp10 + tmp11;
    INT32 t10_12 = tmp10 + tmp12;
    INT32 t10_13 = tmp10 + tmp13;
    INT32 t14_15 = tmp14 + tmp15;
    INT32 d14 = tmp14 * ((INT32)(0.241438564 * (1<<13) + 0.5));
    INT32 d10 = tmp10 * ((INT32)(1.530003162 * (1<<13) + 0.5));

    tmp3 = (t10_13 * ((INT32)(0.710284161 * (1<<13) + 0.5))) + (t14_15 * ((INT32)(0.256335874 * (1<<13) + 0.5)));
    tmp1 = t10_11 * ((INT32)(1.001514908 * (1<<13) + 0.5));
    tmp2 = t10_12 * ((INT32)(0.881514751 * (1<<13) + 0.5));
    tmp0 = tmp1 + tmp2 + tmp3 - d10 + d14;

    // Introduce additional cross-use to create more RAW dependencies
    INT32 base_correction = ((tmp11 + tmp12) * ((INT32)(0.256335874 * (1<<13) + 0.5)));
    tmp4 = ((tmp14 - tmp15) * ((INT32)(0.710284161 * (1<<13) + 0.5))) - base_correction;
    tmp5 = (tmp11 + tmp13) * (-((INT32)(0.881514751 * (1<<13) + 0.5)));
    tmp6 = (tmp12 + tmp13) * (-((INT32)(0.497774438 * (1<<13) + 0.5)));

    tmp1 += tmp4 + tmp5 + (tmp11 * ((INT32)(0.634110155 * (1<<13) + 0.5))) 
           - (tmp14 * ((INT32)(1.773594819 * (1<<13) + 0.5)));
    tmp2 += tmp4 + tmp6 - (tmp12 * ((INT32)(1.190715098 * (1<<13) + 0.5))) 
           + (tmp15 * ((INT32)(1.711799069 * (1<<13) + 0.5)));
    tmp3 += tmp5 + tmp6 + (tmp13 * ((INT32)(1.670519935 * (1<<13) + 0.5))) 
           - (tmp15 * ((INT32)(1.319646532 * (1<<13) + 0.5)));

    dataptr[8 * 1] = (DCTELEM)(((tmp0) + (1 << 13)) >> 14);
    dataptr[8 * 3] = (DCTELEM)(((tmp1) + (1 << 13)) >> 14);
    dataptr[8 * 5] = (DCTELEM)(((tmp2) + (1 << 13)) >> 14);
    dataptr[8 * 7] = (DCTELEM)(((tmp3) + (1 << 13)) >> 14);

    // Preserve state across iterations — introduces loop-carried dependency
    prev_tmp0 = tmp0;

    dataptr++;
    wsptr++;
}
}
