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



void loop() {
    for (js = 0; js < m; js += 2) {
        // Change memory access pattern to indirect via index arrays
        BLASLONG row_idx[4] = {0, 1, 2, 3}; // Local indices for 4-element vectorization

        aa1 = a;
        aa2 = a + lda;
        a += 2 * lda + 4;

        bb1 = b1;
        bb2 = b1 + 2 * m;
        b1 += 4 * m + 4;

        cc1 = b2;
        cc2 = b2 + 2 * m;
        b2 += 4 * m + 4;

        if (m - js >= 2) {
            // First micro-tile using indirect addressing
            a11 = *(aa1 + row_idx[0]); a31 = *(aa1 + row_idx[2]);
            a41 = *(aa1 + row_idx[3]); a12 = *(aa2 + row_idx[2]);

            BLASLONG b_idx[8] = {0, 1, 2, 3, 0, 1, 2, 3};
            float *dest_b[8] = {bb1, bb1, bb1, bb1, bb2, bb2, bb2, bb2};
            float val_b[8] = {a11, 0.0f, a31, a41, a31, -a41, a12, 0.0f};

            for (BLASLONG k = 0; k < 8; ++k) {
                *(dest_b[k] + b_idx[k]) = val_b[k];
            }

            aa1 += 4; aa2 += 4;
            bb1 += 4; bb2 += 4;
            cc1 += 4 * m; cc2 += 4 * m;

            BLASLONG trip_count = (m - js - 2) >> 1;
            for (is = 0; is < trip_count; ++is) {
                a11 = *(aa1 + row_idx[0]); a21 = *(aa1 + row_idx[1]);
                a31 = *(aa1 + row_idx[2]); a41 = *(aa1 + row_idx[3]);
                a12 = *(aa2 + row_idx[0]); a22 = *(aa2 + row_idx[1]);
                a32 = *(aa2 + row_idx[2]); a42 = *(aa2 + row_idx[3]);

                // Use indirect stores through pointer arrays
                float *dest_ptrs_b[8] = {bb1, bb1, bb1, bb1, bb2, bb2, bb2, bb2};
                float *dest_ptrs_c[8] = {cc1, cc1, cc1, cc1, cc2, cc2, cc2, cc2};
                BLASLONG offsets_b[8] = {0, 1, 2, 3, 0, 1, 2, 3};
                BLASLONG offsets_c[8] = {0, 1, 2, 3, 0, 1, 2, 3};

                float vals_b[8] = {a11, a21, a31, a41, a12, a22, a32, a42};
                float vals_c[8] = {a11, -a21, a12, -a22, a31, -a41, a32, -a42};

                for (BLASLONG k = 0; k < 8; ++k) {
                    *(dest_ptrs_b[k] + offsets_b[k]) = vals_b[k];
                    *(dest_ptrs_c[k] + offsets_c[k] * m) = vals_c[k];
                }

                aa1 += 4; aa2 += 4;
                bb1 += 4; bb2 += 4;
                cc1 += 4 * m; cc2 += 4 * m;
            }

            if (m & 1) {
                a11 = *(aa1 + 0); a21 = *(aa1 + 1);
                a12 = *(aa2 + 0); a22 = *(aa2 + 1);

                float *b_dests[4] = {bb1, bb1, bb2, bb2};
                BLASLONG b_offs[4] = {0, 1, 0, 1};
                float b_vals[4] = {a11, a21, a12, a22};

                float *c_dests[4] = {cc1, cc1, cc1, cc1};
                BLASLONG c_offs[4] = {0, 1, 2, 3};
                float c_vals[4] = {a11, -a21, a12, -a22};

                for (BLASLONG k = 0; k < 4; ++k) {
                    *(b_dests[k] + b_offs[k]) = b_vals[k];
                }
                for (BLASLONG k = 0; k < 4; ++k) {
                    *(c_dests[k] + c_offs[k]) = c_vals[k];
                }
            }
        }

        if (m - js == 1) {
            a11 = *(aa1 + 0);
            *(bb1 + 0) = a11;
            *(bb1 + 1) = 0.0f;
        }
    }
}
