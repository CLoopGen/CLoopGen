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
    int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Indirect access pattern via index mapping
    for (ctr = 0; ctr < 8; ++ctr) {
        int mapped_idx = indices[ctr]; // Use indirect indexing into wsptr
        outptr = output_buf[mapped_idx] + output_col;
        tmp10 = wsptr[mapped_idx * 8 + 0] + wsptr[mapped_idx * 8 + 4];
        tmp11 = wsptr[mapped_idx * 8 + 0] - wsptr[mapped_idx * 8 + 4];
        tmp13 = wsptr[mapped_idx * 8 + 2] + wsptr[mapped_idx * 8 + 6];
        tmp12 = (wsptr[mapped_idx * 8 + 2] - wsptr[mapped_idx * 8 + 6]) * ((float)1.414213562) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;
        z13 = wsptr[mapped_idx * 8 + 5] + wsptr[mapped_idx * 8 + 3];
        z10 = wsptr[mapped_idx * 8 + 5] - wsptr[mapped_idx * 8 + 3];
        z11 = wsptr[mapped_idx * 8 + 1] + wsptr[mapped_idx * 8 + 7];
        z12 = wsptr[mapped_idx * 8 + 1] - wsptr[mapped_idx * 8 + 7];
        tmp7 = z11 + z13;
        tmp11 = (z11 - z13) * ((float)1.414213562);
        z5 = (z10 + z12) * ((float)1.847759065);
        tmp10 = ((float)1.0823921999999999) * z12 - z5;
        tmp12 = ((float)-2.6131259299999998) * z10 + z5;
        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;
        outptr[0] = range_limit[(int)((((INT32)(tmp0 + tmp7)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        outptr[7] = range_limit[(int)((((INT32)(tmp0 - tmp7)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)((((INT32)(tmp1 + tmp6)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        outptr[6] = range_limit[(int)((((INT32)(tmp1 - tmp6)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        outptr[2] = range_limit[(int)((((INT32)(tmp2 + tmp5)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        outptr[5] = range_limit[(int)((((INT32)(tmp2 - tmp5)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        outptr[4] = range_limit[(int)((((INT32)(tmp3 + tmp4)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
        outptr[3] = range_limit[(int)((((INT32)(tmp3 - tmp4)) + (((INT32)1) << ((3) - 1))) >> (3)) & (255 * 4 + 3)];
    }
}
