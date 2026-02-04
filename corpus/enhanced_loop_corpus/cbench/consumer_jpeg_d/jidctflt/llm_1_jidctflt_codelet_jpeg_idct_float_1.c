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
for (ctr = 0; ctr < 4; ctr++) {
    for (int sub = 0; sub < 2; sub++) {
        int idx = ctr * 2 + sub;
        JSAMPROW local_outptr = output_buf[idx] + output_col;
        float *local_wsptr = wsptr + idx * 8;
        float t10 = local_wsptr[0] + local_wsptr[4];
        float t11 = local_wsptr[0] - local_wsptr[4];
        float t13 = local_wsptr[2] + local_wsptr[6];
        float t12 = (local_wsptr[2] - local_wsptr[6]) * ((float)1.414213562) - t13;
        float t0 = t10 + t13;
        float t3 = t10 - t13;
        float t1 = t11 + t12;
        float t2 = t11 - t12;
        float z13 = local_wsptr[5] + local_wsptr[3];
        float z10 = local_wsptr[5] - local_wsptr[3];
        float z11 = local_wsptr[1] + local_wsptr[7];
        float z12 = local_wsptr[1] - local_wsptr[7];
        float t7 = z11 + z13;
        float tt11 = (z11 - z13) * ((float)1.414213562);
        float z5 = (z10 + z12) * ((float)1.847759065);
        float t10_val = ((float)1.0823921999999999) * z12 - z5;
        float t12_val = ((float)-2.6131259299999998) * z10 + z5;
        float t6 = t12_val - t7;
        float t5 = tt11 - t6;
        float t4 = t10_val + t5;
        local_outptr[0] = range_limit[(int)((((INT32)(t0 + t7)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        local_outptr[7] = range_limit[(int)((((INT32)(t0 - t7)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        local_outptr[1] = range_limit[(int)((((INT32)(t1 + t6)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        local_outptr[6] = range_limit[(int)((((INT32)(t1 - t6)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        local_outptr[2] = range_limit[(int)((((INT32)(t2 + t5)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        local_outptr[5] = range_limit[(int)((((INT32)(t2 - t5)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        local_outptr[4] = range_limit[(int)((((INT32)(t3 + t4)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        local_outptr[3] = range_limit[(int)((((INT32)(t3 - t4)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
    }
}
}
