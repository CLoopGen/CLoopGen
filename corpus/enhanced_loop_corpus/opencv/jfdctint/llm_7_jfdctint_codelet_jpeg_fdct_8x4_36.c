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
extern INT32 tmp13;
extern INT32 z1;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 4; ctr++) {
    elemptr = sample_data[ctr] + start_col;

    // Reorder computations to eliminate some WAW and WAR hazards by using temporaries
    INT32 t0_add, t1_add, t2_add, t3_add;
    INT32 t0_sub, t1_sub, t2_sub, t3_sub;

    t0_add = ((int)(elemptr[0])) + ((int)(elemptr[7]));
    t1_add = ((int)(elemptr[1])) + ((int)(elemptr[6]));
    t2_add = ((int)(elemptr[2])) + ((int)(elemptr[5]));
    t3_add = ((int)(elemptr[3])) + ((int)(elemptr[4]));

    t0_sub = ((int)(elemptr[0])) - ((int)(elemptr[7]));
    t1_sub = ((int)(elemptr[1])) - ((int)(elemptr[6]));
    t2_sub = ((int)(elemptr[2])) - ((int)(elemptr[5]));
    t3_sub = ((int)(elemptr[3])) - ((int)(elemptr[4]));

    // Break loop-carried dependency by removing any static/global usage
    // Use local variables for intermediate values to minimize side effects
    INT32 local_tmp10 = t0_add + t3_add;
    INT32 local_tmp11 = t1_add + t2_add;
    INT32 local_tmp12 = t0_add - t3_add;
    INT32 local_tmp13 = t1_add - t2_add;

    INT32 local_z1 = ((local_tmp12 + local_tmp13) * (((INT32)4433))) + (((INT32)1) << (13 - 2 - 2));
    dataptr[0] = (DCTELEM)((local_tmp10 + local_tmp11 - 8 * 128) << (2 + 1));
    dataptr[4] = (DCTELEM)((local_tmp10 - local_tmp11) << (2 + 1));
    dataptr[2] = (DCTELEM)((local_z1 + (local_tmp12 * ((INT32)6270))) >> (13 - 2 - 1));
    dataptr[6] = (DCTELEM)((local_z1 - (local_tmp13 * ((INT32)15137))) >> (13 - 2 - 1));

    INT32 sum_02 = t0_sub + t2_sub;
    INT32 sum_13 = t1_sub + t3_sub;
    local_z1 = ((sum_02 + sum_13) * ((INT32)9633)) + (((INT32)1) << (13 - 2 - 2));
    INT32 partA = (sum_02 * (-(INT32)3196)) + local_z1;
    INT32 partB = (sum_13 * (-(INT32)16069)) + local_z1;

    INT32 mix_03 = t0_sub + t3_sub;
    INT32 mix_12 = t1_sub + t2_sub;

    dataptr[1] = (DCTELEM)((((t0_sub * (INT32)12299) + (mix_03 * (-(INT32)7373)) + partA)) >> (13 - 2 - 1));
    dataptr[3] = (DCTELEM)((((t1_sub * (INT32)25172) + (mix_12 * (-(INT32)20995)) + partB)) >> (13 - 2 - 1));
    dataptr[5] = (DCTELEM)((((t2_sub * (INT32)16819) + (mix_12 * (-(INT32)20995)) + partA)) >> (13 - 2 - 1));
    dataptr[7] = (DCTELEM)((((t3_sub * (INT32)2446) + (mix_03 * (-(INT32)7373)) + partB)) >> (13 - 2 - 1));

    dataptr += 8;
}
}
