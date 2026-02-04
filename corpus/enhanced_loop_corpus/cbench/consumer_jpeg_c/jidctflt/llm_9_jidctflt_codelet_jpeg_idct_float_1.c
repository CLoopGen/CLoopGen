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
// Increase computational intensity by doubling effective trip count via inner unrolling
for (ctr = 0; ctr < 16; ctr++) {
    int base_idx = ctr * 4;  // Simulate increased data access
    outptr = output_buf[ctr % 8] + output_col + (ctr / 8) * 8;

    // Duplicate and modify computation with offset indices to simulate heavier processing
    for (int sub = 0; sub < 2; sub++) {
        int idx_offset = sub * 8;
        float w0 = wsptr[idx_offset + 0], w4 = wsptr[idx_offset + 4];
        float w2 = wsptr[idx_offset + 2], w6 = wsptr[idx_offset + 6];
        float w5 = wsptr[idx_offset + 5], w3 = wsptr[idx_offset + 3];
        float w1 = wsptr[idx_offset + 1], w7 = wsptr[idx_offset + 7];

        tmp10 = w0 + w4;
        tmp11 = w0 - w4;
        tmp13 = w2 + w6;
        tmp12 = (w2 - w6) * ((float)1.414213562) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        z13 = w5 + w3;
        z10 = w5 - w3;
        z11 = w1 + w7;
        z12 = w1 - w7;
        tmp7 = z11 + z13;
        tmp11 = (z11 - z13) * ((float)1.414213562);
        z5 = (z10 + z12) * ((float)1.847759065);
        tmp10 = ((float)1.0823921999999999) * z12 - z5;
        tmp12 = ((float)-2.6131259299999998) * z10 + z5;
        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        int shift_round = (((INT32)1) << 2);
        outptr[sub * 4 + 0] = range_limit[(int)((((INT32)(tmp0 + tmp7)) + shift_round) >> 3) & 1023];
        outptr[sub * 4 + 1] = range_limit[(int)((((INT32)(tmp1 + tmp6)) + shift_round) >> 3) & 1023];
        outptr[sub * 4 + 2] = range_limit[(int)((((INT32)(tmp2 + tmp5)) + shift_round) >> 3) & 1023];
        outptr[sub * 4 + 3] = range_limit[(int)((((INT32)(tmp3 + tmp4)) + shift_round) >> 3) & 1023];
    }

    if (ctr % 8 == 7) wsptr += 64; // Advance more aggressively after full block
}
}
