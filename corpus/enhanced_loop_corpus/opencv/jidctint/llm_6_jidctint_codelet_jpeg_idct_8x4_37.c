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
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    z2 = (INT32)wsptr[0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
    z3 = (INT32)wsptr[4];
    tmp0 = (z2 + z3) << 13;
    tmp1 = (z2 - z3) << 13;
    z2 = (INT32)wsptr[2];
    z3 = (INT32)wsptr[6];
    z1 = ((z2 + z3) * (((INT32)4433)));
    tmp2 = z1 + ((z2) * (((INT32)6270)));
    tmp3 = z1 - ((z3) * (((INT32)15137)));
    tmp10 = tmp0 + tmp2;
    tmp13 = tmp0 - tmp2;
    tmp11 = tmp1 + tmp3;
    tmp12 = tmp1 - tmp3;

    // Introduce temporary variables to break direct dependencies and reorder operations
    INT32 t0, t1, t2, t3;
    t0 = (INT32)wsptr[7];
    t1 = (INT32)wsptr[5];
    t2 = (INT32)wsptr[3];
    t3 = (INT32)wsptr[1];

    // Reorder computation to remove immediate use after store (reduce RAW)
    INT32 u0 = t0 + t2;
    INT32 u1 = t1 + t3;
    INT32 v1 = ((u0 + u1) * (((INT32)9633)));
    INT32 v2 = ((u0) * (-((INT32)16069))) + v1;
    INT32 v3 = ((u1) * (-((INT32)3196))) + v1;

    INT32 w0 = ((t0 + t3) * (-((INT32)7373)));
    INT32 w1 = ((t1 + t2) * (-((INT32)20995)));

    tmp0 = ((t0) * (((INT32)2446))) + w0 + v2;
    tmp3 = ((t3) * (((INT32)12299))) + w0 + v3;
    tmp1 = ((t1) * (((INT32)16819))) + w1 + v3;
    tmp2 = ((t2) * (((INT32)25172))) + w1 + v2;

    // Maintain same output logic with reordered but equivalent expressions
    outptr[0] = range_limit[(int)((tmp10 + tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[7] = range_limit[(int)((tmp10 - tmp3) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[1] = range_limit[(int)((tmp11 + tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[6] = range_limit[(int)((tmp11 - tmp2) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[2] = range_limit[(int)((tmp12 + tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[5] = range_limit[(int)((tmp12 - tmp1) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[3] = range_limit[(int)((tmp13 + tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    outptr[4] = range_limit[(int)((tmp13 - tmp0) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];

    wsptr += 8;
}
}
