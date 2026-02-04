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
extern float a12;
extern float a21;
extern float a22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (js = 0; js < m; js += 2) {
    BLASLONG offset_a_col0 = 0;
    BLASLONG offset_a_col1 = lda;
    BLASLONG offset_b1_row0 = 0;
    BLASLONG offset_b1_row1 = m;
    BLASLONG offset_b2_row0 = 0;
    BLASLONG offset_b2_row1 = 1;
    for (is = 0; is < js && (m - js >= 2); is += 2) {
        a11 = *(a + offset_a_col0 + is);
        a21 = *(a + offset_a_col0 + is + 1);
        a12 = *(a + offset_a_col1 + is);
        a22 = *(a + offset_a_col1 + is + 1);
        *(b1 + offset_b1_row0 + is) = a11;
        *(b1 + offset_b1_row0 + is + 1) = a21;
        *(b1 + offset_b1_row1 + is) = a12;
        *(b1 + offset_b1_row1 + is + 1) = a22;
        *(b2 + offset_b2_row0 + is * m) = a11;
        *(b2 + offset_b2_row0 + is * m + 1) = a12;
        *(b2 + offset_b2_row1 + is * m) = a21;
        *(b2 + offset_b2_row1 + is * m + 1) = a22;
    }
    if (m - js >= 2) {
        a11 = *(a + offset_a_col0 + js);
        a12 = *(a + offset_a_col1 + js);
        a22 = *(a + offset_a_col1 + js + 1);
        *(b1 + offset_b1_row0 + js) = a11;
        *(b1 + offset_b1_row0 + js + 1) = a12;
        *(b1 + offset_b1_row1 + js) = a12;
        *(b1 + offset_b1_row1 + js + 1) = a22;
        a += 2 * lda;
        b1 += 2 * m;
        b2 += 2;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(a + 0 * lda + is);
            a21 = *(a + 0 * lda + is + 1);
            *(b1 + 0 * m + is) = a11;
            *(b1 + 0 * m + is + 1) = a21;
            *(b2 + 0 * m + is * m) = a11;
            *(b2 + 1 * m + is * m) = a21;
        }
        a11 = *(a + 0 * lda + js);
        *(b1 + 0 * m + js) = a11;
        a += 2 * lda;
        b1 += 2 * m;
        b2 += 2;
    }
}
}
