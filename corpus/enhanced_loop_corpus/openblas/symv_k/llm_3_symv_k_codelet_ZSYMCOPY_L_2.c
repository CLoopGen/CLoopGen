#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern float *a;
extern BLASLONG lda;
extern BLASLONG is;
extern BLASLONG js;
extern float *aa1;
extern float *aa2;
extern float *b1;
extern float *b2;
extern float *bb1;
extern float *bb2;
extern float *cc1;
extern float *cc2;
extern float a11;
extern float a21;
extern float a31;
extern float a41;
extern float a12;
extern float a22;
extern float a32;
extern float a42;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (js = 0; js < m; js += 2) {
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda + 4;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 2 * m;
    b1 += 4 * m + 4;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 2 * m;
    b2 += 4 * m + 4;

    if (m - js >= 2) {
        float temp_A[8], temp_B[8], temp_C[8];
        float *src_rows[2] = {aa1, aa2};
        float *dst_B[2] = {bb1, bb2};
        float *dst_C_cols[2] = {cc1, cc2};

        a11 = src_rows[0][0]; a21 = src_rows[0][1]; a31 = src_rows[0][2]; a41 = src_rows[0][3];
        a12 = src_rows[1][2]; a22 = src_rows[1][3];

        dst_B[0][0] = a11; dst_B[0][1] = a21; dst_B[0][2] = a31; dst_B[0][3] = a41;
        dst_B[1][0] = a31; dst_B[1][1] = a41; dst_B[1][2] = a12; dst_B[1][3] = a22;

        BLASLONG unroll_count = (m - js - 2) >> 1;
        for (BLASLONG k = 0; k < unroll_count; k++) {
            BLASLONG offset = 4 * (k + 1);
            for (int i = 0; i < 8; i++) {
                temp_A[i] = *(src_rows[i >> 2] + offset + (i & 3));
            }

            for (int i = 0; i < 8; i++) {
                temp_B[i] = temp_A[i];
                temp_C[i] = (i < 4) ? temp_A[i] : temp_A[i-4+4*((i&1)<<1)];
            }

            for (int i = 0; i < 4; i++) {
                dst_B[0][offset + i] = temp_B[i];
                dst_B[1][offset + i] = temp_B[i + 4];
                dst_C_cols[0][offset*m + i] = temp_C[i];
                dst_C_cols[1][offset*m + i] = temp_C[i + 4];
            }
        }

        if (m & 1) {
            BLASLONG offset = 4 * unroll_count;
            a11 = src_rows[0][offset]; a21 = src_rows[0][offset+1];
            a12 = src_rows[1][offset]; a22 = src_rows[1][offset+1];

            dst_B[0][offset] = a11; dst_B[0][offset+1] = a21;
            dst_B[1][offset] = a12; dst_B[1][offset+1] = a22;
            dst_C_cols[0][offset*m] = a11; dst_C_cols[0][offset*m+1] = a21;
            dst_C_cols[0][offset*m+2] = a12; dst_C_cols[0][offset*m+3] = a22;
        }
    }

    if (m - js == 1) {
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
    }
}
}
