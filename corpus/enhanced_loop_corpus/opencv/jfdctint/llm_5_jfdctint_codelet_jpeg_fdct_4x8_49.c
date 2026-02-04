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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 4; ctr++) {
    DCTELEM* base_ptr = dataptr;
    tmp0 = base_ptr[8 * 0] + base_ptr[8 * 7];
    tmp1 = base_ptr[8 * 1] + base_ptr[8 * 6];
    tmp2 = base_ptr[8 * 2] + base_ptr[8 * 5];
    tmp3 = base_ptr[8 * 3] + base_ptr[8 * 4];
    tmp10 = tmp0 + tmp3 + (((INT32)1) << (2 - 1));
    tmp12 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp13 = tmp1 - tmp2;
    tmp0 = base_ptr[8 * 0] - base_ptr[8 * 7];
    tmp1 = base_ptr[8 * 1] - base_ptr[8 * 6];
    tmp2 = base_ptr[8 * 2] - base_ptr[8 * 5];
    tmp3 = base_ptr[8 * 3] - base_ptr[8 * 4];
    dataptr[8 * 0] = (DCTELEM)(((tmp10 + tmp11) >> 2));
    dataptr[8 * 4] = (DCTELEM)(((tmp10 - tmp11) >> 2));
    z1 = ((tmp12 + tmp13) * (((INT32)4433))) + (((INT32)1) << (13 + 2 - 1));
    dataptr[8 * 2] = (DCTELEM)((z1 + (tmp12 * ((INT32)6270))) >> (15));
    dataptr[8 * 6] = (DCTELEM)((z1 - (tmp13 * ((INT32)15137))) >> (15));
    INT32 next_tmp12 = tmp0 + tmp2;
    INT32 next_tmp13 = tmp1 + tmp3;
    z1 = (next_tmp12 + next_tmp13) * ((INT32)9633);
    z1 += ((INT32)1) << 14;
    INT32 partA = (next_tmp12 * (-((INT32)3196))) + z1;
    INT32 partB = (next_tmp13 * (-((INT32)16069))) + z1;
    z1 = (tmp0 + tmp3) * (-((INT32)7373));
    tmp0 = (tmp0 * ((INT32)12299)) + z1 + partA;
    tmp3 = (tmp3 * ((INT32)2446)) + z1 + partB;
    z1 = (tmp1 + tmp2) * (-((INT32)20995));
    tmp1 = (tmp1 * ((INT32)25172)) + z1 + partB;
    tmp2 = (tmp2 * ((INT32)16819)) + z1 + partA;
    dataptr[8 * 1] = (DCTELEM)(tmp0 >> 15);
    dataptr[8 * 3] = (DCTELEM)(tmp1 >> 15);
    dataptr[8 * 5] = (DCTELEM)(tmp2 >> 15);
    dataptr[8 * 7] = (DCTELEM)(tmp3 >> 15);
    dataptr = base_ptr + 1;
}
}
