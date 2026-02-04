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
    BLASLONG offset_a = 0 * lda;
    BLASLONG offset_aa = 1 * lda;
    aa1 = a + offset_a;
    aa2 = a + offset_aa;
    a += 2 * lda;
    BLASLONG idx_b = 0;
    bb1 = b1 + idx_b;
    bb2 = b1 + m;
    b1 += 2 * m;
    cc1 = b2;
    cc2 = b2 + 1;
    b2 += 2;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            BLASLONG i = is;
            float temp_a11 = *(aa1 + i);
            float temp_a21 = *(aa1 + i + 1);
            float temp_a12 = *(aa2 + i);
            float temp_a22 = *(aa2 + i + 1);
            *(bb1 + i) = temp_a11;
            *(bb1 + i + 1) = temp_a21;
            *(bb2 + i) = temp_a12;
            *(bb2 + i + 1) = temp_a22;
            *(cc1 + i * m) = temp_a11;
            *(cc1 + i * m + 1) = temp_a12;
            *(cc2 + i * m) = temp_a21;
            *(cc2 + i * m + 1) = temp_a22;
        }
        float temp_a11 = *(aa1 + js);
        float temp_a12 = *(aa2 + js);
        float temp_a22 = *(aa2 + js + 1);
        *(bb1 + js) = temp_a11;
        *(bb1 + js + 1) = temp_a12;
        *(bb2 + js) = temp_a12;
        *(bb2 + js + 1) = temp_a22;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            BLASLONG i = is;
            float temp_a11 = *(aa1 + i);
            float temp_a21 = *(aa1 + i + 1);
            *(bb1 + i) = temp_a11;
            *(bb1 + i + 1) = temp_a21;
            *(cc1 + i * m) = temp_a11;
            *(cc2 + i * m) = temp_a21;
        }
        float temp_a11 = *(aa1 + js);
        *(bb1 + js) = temp_a11;
    }
}
}
