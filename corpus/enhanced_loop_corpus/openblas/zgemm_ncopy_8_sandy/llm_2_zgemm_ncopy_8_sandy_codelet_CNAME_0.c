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

    for (i = 0; i < row / 4; i += 1) {
        // Interleaved write pattern: group by source pointer instead of sequential layout
        for (BLASLONG k = 0; k < 8; k++) {
            float *src_ptr = (k == 0) ? src0 : (k == 1) ? src1 : (k == 2) ? src2 :
                            (k == 3) ? src3 : (k == 4) ? src4 : (k == 5) ? src5 :
                            (k == 6) ? src6 : src7;
            BLASLONG offset = k * 8;
            dest0[offset + 0] = src_ptr[0];
            dest0[offset + 1] = src_ptr[1];
            dest0[offset + 2] = src_ptr[2];
            dest0[offset + 3] = src_ptr[3];
            dest0[offset + 4] = src_ptr[4];
            dest0[offset + 5] = src_ptr[5];
            dest0[offset + 6] = src_ptr[6];
            dest0[offset + 7] = src_ptr[7];
        }

        src0 += 8; src1 += 8; src2 += 8; src3 += 8;
        src4 += 8; src5 += 8; src6 += 8; src7 += 8;
        dest0 += 64; // 4 rows * 16 elements per row in transposed block
    }

    if (row & 2) {
        for (BLASLONG k = 0; k < 8; k++) {
            float *src_ptr = (k == 0) ? src0 : (k == 1) ? src1 : (k == 2) ? src2 :
                            (k == 3) ? src3 : (k == 4) ? src4 : (k == 5) ? src5 :
                            (k == 6) ? src6 : src7;
            BLASLONG offset = k * 4;
            dest0[offset + 0] = src_ptr[0];
            dest0[offset + 1] = src_ptr[1];
            dest0[offset + 2] = src_ptr[2];
            dest0[offset + 3] = src_ptr[3];
        }
        src0 += 4; src1 += 4; src2 += 4; src3 += 4;
        src4 += 4; src5 += 4; src6 += 4; src7 += 4;
        dest0 += 32;
    }

    if (row & 1) {
        for (BLASLONG k = 0; k < 8; k++) {
            float *src_ptr = (k == 0) ? src0 : (k == 1) ? src1 : (k == 2) ? src2 :
                            (k == 3) ? src3 : (k == 4) ? src4 : (k == 5) ? src5 :
                            (k == 6) ? src6 : src7;
            BLASLONG offset = k * 2;
            dest0[offset + 0] = src_ptr[0];
            dest0[offset + 1] = src_ptr[1];
        }
        src0 += 2; src1 += 2; src2 += 2; src3 += 2;
        src4 += 2; src5 += 2; src6 += 2; src7 += 2;
        dest0 += 16;
    }
}
}
