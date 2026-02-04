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
        float vec_a[8], vec_b[8];
        float *src_rows[2] = { aa1, aa2 };
        float *dst_b_rows[2] = { bb1, bb2 };
        float *dst_c_cols[2] = { cc1, cc2 };

        a11 = src_rows[0][0]; a21 = src_rows[0][1]; a31 = src_rows[0][2]; a41 = src_rows[0][3];
        a12 = src_rows[1][2]; a22 = src_rows[1][3];

        dst_b_rows[0][0] = a11; dst_b_rows[0][1] = a21; dst_b_rows[0][2] = a31; dst_b_rows[0][3] = a41;
        dst_b_rows[1][0] = a31; dst_b_rows[1][1] = a41; dst_b_rows[1][2] = a12; dst_b_rows[1][3] = a22;

        BLASLONG unroll_count = (m - js - 2) >> 1;
        for (BLASLONG i = 0; i < unroll_count; i++) {
            BLASLONG offset = 4 * (i + 1);
            vec_a[0] = src_rows[0][offset + 0]; vec_a[1] = src_rows[0][offset + 1];
            vec_a[2] = src_rows[0][offset + 2]; vec_a[3] = src_rows[0][offset + 3];
            vec_a[4] = src_rows[1][offset + 0]; vec_a[5] = src_rows[1][offset + 1];
            vec_a[6] = src_rows[1][offset + 2]; vec_a[7] = src_rows[1][offset + 3];

            dst_b_rows[0][offset + 0] = vec_a[0]; dst_b_rows[0][offset + 1] = vec_a[1];
            dst_b_rows[0][offset + 2] = vec_a[2]; dst_b_rows[0][offset + 3] = vec_a[3];
            dst_b_rows[1][offset + 0] = vec_a[4]; dst_b_rows[1][offset + 1] = vec_a[5];
            dst_b_rows[1][offset + 2] = vec_a[6]; dst_b_rows[1][offset + 3] = vec_a[7];

            BLASLONG c_offset = i * 4 * m;
            dst_c_cols[0][c_offset + 0] = vec_a[0]; dst_c_cols[0][c_offset + 1] = vec_a[1];
            dst_c_cols[0][c_offset + 2] = vec_a[4]; dst_c_cols[0][c_offset + 3] = vec_a[5];
            dst_c_cols[1][c_offset + 0] = vec_a[2]; dst_c_cols[1][c_offset + 1] = vec_a[3];
            dst_c_cols[1][c_offset + 2] = vec_a[6]; dst_c_cols[1][c_offset + 3] = vec_a[7];
        }

        if (m & 1) {
            BLASLONG last_offset = 4 * unroll_count;
            a11 = src_rows[0][last_offset]; a21 = src_rows[0][last_offset + 1];
            a12 = src_rows[1][last_offset]; a22 = src_rows[1][last_offset + 1];

            dst_b_rows[0][last_offset + 0] = a11; dst_b_rows[0][last_offset + 1] = a21;
            dst_b_rows[1][last_offset + 0] = a12; dst_b_rows[1][last_offset + 1] = a22;
            dst_c_cols[0][0] = a11; dst_c_cols[0][1] = a21;
            dst_c_cols[0][2] = a12; dst_c_cols[0][3] = a22;
        }
    }

    if (m - js == 1) {
        a11 = aa1[0]; a21 = aa1[1];
        bb1[0] = a11; bb1[1] = a21;
    }
}
}
