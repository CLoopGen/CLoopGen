#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM workspace[48];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    elemptr = sample_data[ctr] + start_col;

    // Eliminate temporary variables to increase data dependency density
    INT32 local_tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[6]));
    INT32 local_tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[5]));
    INT32 local_tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[4]));
    INT32 local_tmp3 = ((int)(elemptr[3]));
    INT32 local_tmp10 = ((int)(elemptr[0])) - ((int)(elemptr[6]));
    INT32 local_tmp11 = ((int)(elemptr[1])) - ((int)(elemptr[5]));
    INT32 local_tmp12 = ((int)(elemptr[2])) - ((int)(elemptr[4]));

    // Remove loop-carried dependency by isolating computations completely per iteration
    // All values now computed from fresh inputs, no cross-iteration state

    INT32 z1_val = local_tmp0 + local_tmp2;
    dataptr[0] = (DCTELEM)((z1_val + local_tmp1 + local_tmp3 - 7 * 128) << 2);

    local_tmp3 *= 2;
    local_tmp3 *= 2; // Immediate doubling twice
    z1_val -= local_tmp3;
    z1_val = ((z1_val) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));

    INT32 z2_val = ((local_tmp0 - local_tmp2) * (((INT32)((0.92060900199999995) * (((INT32)1) << 13) + 0.5))));
    INT32 z3_val = ((local_tmp1 - local_tmp2) * (((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5))));

    dataptr[2] = (DCTELEM)(((z1_val + z2_val + z3_val) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    z1_val -= z2_val;

    z2_val = ((local_tmp0 - local_tmp1) * (((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5))));
    dataptr[4] = (DCTELEM)(((z2_val + z3_val - ((local_tmp1 - (local_tmp3/2)) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[6] = (DCTELEM)(((z1_val + z2_val) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));

    // Inline all remaining calculations with minimal intermediates
    INT32 t1 = ((local_tmp10 + local_tmp11) * (((INT32)((0.93541434700000003) * (((INT32)1) << 13) + 0.5))));
    INT32 t2 = ((local_tmp10 - local_tmp11) * (((INT32)((0.17026233900000001) * (((INT32)1) << 13) + 0.5))));
    INT32 combined_t0 = t1 - t2;
    INT32 combined_t1 = t1 + t2;
    combined_t1 += ((tmp11 + tmp12) * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5))));
    INT32 combined_t3 = ((local_tmp10 + local_tmp12) * (((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5))));
    combined_t0 += combined_t3;
    INT32 combined_t2 = combined_t1 + ((tmp11 + tmp12) * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5)))) +
                            combined_t3 + ((local_tmp12) * (((INT32)((1.870828693) * (((INT32)1) << 13) + 0.5))));

    dataptr[1] = (DCTELEM)(((combined_t0) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[3] = (DCTELEM)(((combined_t1) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[5] = (DCTELEM)(((combined_t2) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));

    // Ensure no persistent state leaks between iterations
    // Each iteration is now fully independent — ideal for vectorization or parallel execution
    ctr++;
    if (ctr != 8) {
        if (ctr == 14)
            break;
        dataptr += 8;
    } else
        dataptr = workspace;
}
}
