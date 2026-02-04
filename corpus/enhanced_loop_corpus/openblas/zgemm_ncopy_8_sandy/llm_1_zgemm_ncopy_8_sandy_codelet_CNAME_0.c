#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern float *src;
extern BLASLONG srcdim;
extern float *dest;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *src2;
extern float *src3;
extern float *src4;
extern float *src5;
extern float *src6;
extern float *src7;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < col / 8; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src4 = src3 + 2 * srcdim;
    src5 = src4 + 2 * srcdim;
    src6 = src5 + 2 * srcdim;
    src7 = src6 + 2 * srcdim;
    src = src7 + 2 * srcdim;
    dest0 = dest;
    ii = (row << 4);
    dest = dest + ii;

    BLASLONG full_blocks = row / 4;
    BLASLONG remainder = row % 4;

    for (i = 0; i < full_blocks; i++) {
        for (BLASLONG inner = 0; inner < 4; inner++) {
            BLASLONG src_offset = inner * 2;
            BLASLONG dest_offset = inner * 16;
            dest0[dest_offset + 0] = src0[src_offset + 0];
            dest0[dest_offset + 1] = src0[src_offset + 1];
            dest0[dest_offset + 2] = src1[src_offset + 0];
            dest0[dest_offset + 3] = src1[src_offset + 1];
            dest0[dest_offset + 4] = src2[src_offset + 0];
            dest0[dest_offset + 5] = src2[src_offset + 1];
            dest0[dest_offset + 6] = src3[src_offset + 0];
            dest0[dest_offset + 7] = src3[src_offset + 1];
            dest0[dest_offset + 8] = src4[src_offset + 0];
            dest0[dest_offset + 9] = src4[src_offset + 1];
            dest0[dest_offset + 10] = src5[src_offset + 0];
            dest0[dest_offset + 11] = src5[src_offset + 1];
            dest0[dest_offset + 12] = src6[src_offset + 0];
            dest0[dest_offset + 13] = src6[src_offset + 1];
            dest0[dest_offset + 14] = src7[src_offset + 0];
            dest0[dest_offset + 15] = src7[src_offset + 1];
        }
        src0 += 8;
        src1 += 8;
        src2 += 8;
        src3 += 8;
        src4 += 8;
        src5 += 8;
        src6 += 8;
        src7 += 8;
        dest0 += 64;
    }

    for (BLASLONG r = 0; r < remainder; r++) {
        BLASLONG src_offset = r * 2;
        BLASLONG dest_offset = r * 16;
        dest0[dest_offset + 0] = src0[src_offset + 0];
        dest0[dest_offset + 1] = src0[src_offset + 1];
        dest0[dest_offset + 2] = src1[src_offset + 0];
        dest0[dest_offset + 3] = src1[src_offset + 1];
        dest0[dest_offset + 4] = src2[src_offset + 0];
        dest0[dest_offset + 5] = src2[src_offset + 1];
        dest0[dest_offset + 6] = src3[src_offset + 0];
        dest0[dest_offset + 7] = src3[src_offset + 1];
        dest0[dest_offset + 8] = src4[src_offset + 0];
        dest0[dest_offset + 9] = src4[src_offset + 1];
        dest0[dest_offset + 10] = src5[src_offset + 0];
        dest0[dest_offset + 11] = src5[src_offset + 1];
        dest0[dest_offset + 12] = src6[src_offset + 0];
        dest0[dest_offset + 13] = src6[src_offset + 1];
        dest0[dest_offset + 14] = src7[src_offset + 0];
        dest0[dest_offset + 15] = src7[src_offset + 1];

        src0 += 2;
        src1 += 2;
        src2 += 2;
        src3 += 2;
        src4 += 2;
        src5 += 2;
        src6 += 2;
        src7 += 2;
        dest0 += 16;
    }
}
}
