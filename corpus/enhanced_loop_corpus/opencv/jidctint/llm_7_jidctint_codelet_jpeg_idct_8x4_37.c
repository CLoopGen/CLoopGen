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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependency by unrolling and fusing computations
// Also restructure to minimize WAW and WAR hazards via local temporaries

for (ctr = 0; ctr < 4; ++ctr) {
    JSAMPROW local_outptr = output_buf[ctr] + output_col;
    int* local_wsptr = wsptr;  // Break potential aliasing early

    // Precompute common shift values to reduce redundancy
    const int SHIFT_AMOUNT = 13 + 2 + 3;
    const int MASK = ((128 << 2) * 2 - 1);
    const INT32 OFFSET = ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));

    // Use block-local temporaries to eliminate false dependencies
    INT32 block_tmp0, block_tmp1, block_tmp2, block_tmp3;
    INT32 block_z1, block_z2, block_z3;
    INT32 stage0, stage1, stage2, stage3;

    // First transform stage with immediate folding
    block_z2 = (INT32)local_wsptr[0] + OFFSET;
    block_z3 = (INT32)local_wsptr[4];
    stage0 = (block_z2 + block_z3) << 13;
    stage1 = (block_z2 - block_z3) << 13;

    block_z2 = (INT32)local_wsptr[2];
    block_z3 = (INT32)local_wsptr[6];
    block_z1 = (block_z2 + block_z3) * (INT32)4433;
    stage2 = block_z1 + (block_z2 * (INT32)6270);
    stage3 = block_z1 - (block_z3 * (INT32)15137);

    // Combine stages into final transform inputs
    INT32 A0 = stage0 + stage2;
    INT32 A3 = stage0 - stage2;
    INT32 A1 = stage1 + stage3;
    INT32 A2 = stage1 - stage3;

    // Second transform stage using fused arithmetic
    block_tmp0 = (INT32)local_wsptr[7];
    block_tmp1 = (INT32)local_wsptr[5];
    block_tmp2 = (INT32)local_wsptr[3];
    block_tmp3 = (INT32)local_wsptr[1];

    block_z2 = block_tmp0 + block_tmp2;
    block_z3 = block_tmp1 + block_tmp3;
    block_z1 = (block_z2 + block_z3) * (INT32)9633;

    // Fused multiply-add style updates to avoid intermediate write-read chains
    block_tmp0 = (block_tmp0 * (INT32)2446) + ((block_tmp0 + block_tmp3) * (-7373)) + (block_z1 - (block_z2 * 16069));
    block_tmp3 = (block_tmp3 * (INT32)12299) + ((block_tmp0 + block_tmp3 - (block_tmp0 - (INT32)2446)) * (-7373)) + (block_z1 - (block_z3 * 3196));

    block_tmp1 = (block_tmp1 * (INT32)16819) + ((block_tmp1 + block_tmp2) * (-20995)) + (block_z1 - (block_z3 * 3196));
    block_tmp2 = (block_tmp2 * (INT32)25172) + ((block_tmp1 + block_tmp2) * (-20995)) + (block_z1 - (block_z2 * 16069));

    // Final outputs with consistent scaling and clamping
    local_outptr[0] = range_limit[(int)((A0 + block_tmp3) >> SHIFT_AMOUNT) & MASK];
    local_outptr[7] = range_limit[(int)((A0 - block_tmp3) >> SHIFT_AMOUNT) & MASK];
    local_outptr[1] = range_limit[(int)((A1 + block_tmp2) >> SHIFT_AMOUNT) & MASK];
    local_outptr[6] = range_limit[(int)((A1 - block_tmp2) >> SHIFT_AMOUNT) & MASK];
    local_outptr[2] = range_limit[(int)((A2 + block_tmp1) >> SHIFT_AMOUNT) & MASK];
    local_outptr[5] = range_limit[(int)((A2 - block_tmp1) >> SHIFT_AMOUNT) & MASK];
    local_outptr[3] = range_limit[(int)((A3 + block_tmp0) >> SHIFT_AMOUNT) & MASK];
    local_outptr[4] = range_limit[(int)((A3 - block_tmp0) >> SHIFT_AMOUNT) & MASK];

    wsptr += 8;  // Update shared pointer only once per iteration
}
}
