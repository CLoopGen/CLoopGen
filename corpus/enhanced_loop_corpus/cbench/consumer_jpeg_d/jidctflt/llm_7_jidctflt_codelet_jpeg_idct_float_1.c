#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern float tmp0;
extern float tmp1;
extern float tmp2;
extern float tmp3;
extern float tmp4;
extern float tmp5;
extern float tmp6;
extern float tmp7;
extern float tmp10;
extern float tmp11;
extern float tmp12;
extern float tmp13;
extern float z5;
extern float z10;
extern float z11;
extern float z12;
extern float z13;
extern float *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float local_wsptr[8][8]; // Eliminate loop-carried dependency by copying data into private array
for (ctr = 0; ctr < 8; ctr++) {
    for (int i = 0; i < 8; i++) {
        local_wsptr[ctr][i] = wsptr[i]; // Private copy removes aliasing and enables parallelism
    }
}

for (ctr = 0; ctr < 8; ctr++) {
    outptr = output_buf[ctr] + output_col;
    tmp10 = local_wsptr[ctr][0] + local_wsptr[ctr][4];
    tmp11 = local_wsptr[ctr][0] - local_wsptr[ctr][4];
    tmp13 = local_wsptr[ctr][2] + local_wsptr[ctr][6];
    tmp12 = (local_wsptr[ctr][2] - local_wsptr[ctr][6]) * ((float)1.414213562) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    z13 = local_wsptr[ctr][5] + local_wsptr[ctr][3];
    z10 = local_wsptr[ctr][5] - local_wsptr[ctr][3];
    z11 = local_wsptr[ctr][1] + local_wsptr[ctr][7];
    z12 = local_wsptr[ctr][1] - local_wsptr[ctr][7];
    tmp7 = z11 + z13;
    tmp11 = (z11 - z13) * ((float)1.414213562);
    z5 = (z10 + z12) * ((float)1.847759065);
    tmp10 = ((float)1.0823921999999999) * z12 - z5;
    tmp12 = ((float)-2.6131259299999998) * z10 + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;

    // All computations now independent across iterations — no loop-carried dependencies
    outptr[0] = range_limit[(int)((((INT32)(tmp0 + tmp7)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
    outptr[7] = range_limit[(int)((((INT32)(tmp0 - tmp7)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)((((INT32)(tmp1 + tmp6)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
    outptr[6] = range_limit[(int)((((INT32)(tmp1 - tmp6)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
    outptr[2] = range_limit[(int)((((INT32)(tmp2 + tmp5)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
    outptr[5] = range_limit[(int)((((INT32)(tmp2 - tmp5)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
    outptr[4] = range_limit[(int)((((INT32)(tmp3 + tmp4)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
    outptr[3] = range_limit[(int)((((INT32)(tmp3 - tmp4)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
}
// Advance wsptr only after full loop to break WAW/WAR hazards
wsptr += 64; // total advance: 8*8
}
