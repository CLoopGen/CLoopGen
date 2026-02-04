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
float * restrict r_a1, * restrict r_a2;
float * restrict r_b1, * restrict r_b2;
float * restrict r_c1, * restrict r_c2;
for (js = 0; js < m; js += 2) {
    r_a1 = a + 0 * lda;
    r_a2 = a + 1 * lda;
    a += 2 * lda;
    r_b1 = b1;
    r_b2 = b1 + 2;
    b1 += 4 * m;
    r_c1 = b2;
    r_c2 = b2 + 2;
    b2 += 4;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            a11 = r_a1[is * 4 + 0]; a21 = r_a1[is * 4 + 1];
            a31 = r_a1[is * 4 + 2]; a41 = r_a1[is * 4 + 3];
            a12 = r_a2[is * 4 + 0]; a22 = r_a2[is * 4 + 1];
            a32 = r_a2[is * 4 + 2]; a42 = r_a2[is * 4 + 3];
            r_b1[is * 4 + 0] = a11; r_b1[is * 4 + 1] = a21;
            r_b1[is * 4 + 2] = a31; r_b1[is * 4 + 3] = a41;
            r_b2[is * 4 + 0] = a12; r_b2[is * 4 + 1] = a22;
            r_b2[is * 4 + 2] = a32; r_b2[is * 4 + 3] = a42;
            r_c1[(is/2) * 4*m + 0] = a11; r_c1[(is/2) * 4*m + 1] = a21;
            r_c1[(is/2) * 4*m + 2] = a12; r_c1[(is/2) * 4*m + 3] = a22;
            r_c2[(is/2) * 4*m + 0] = a31; r_c2[(is/2) * 4*m + 1] = a41;
            r_c2[(is/2) * 4*m + 2] = a32; r_c2[(is/2) * 4*m + 3] = a42;
        }
        a11 = r_a1[js * 2 + 0]; a21 = r_a1[js * 2 + 1];
        a12 = r_a2[js * 2 + 0]; a22 = r_a2[js * 2 + 1];
        a32 = r_a2[js * 2 + 2]; a42 = r_a2[js * 2 + 3];
        r_b1[js * 2 + 0] = a11; r_b1[js * 2 + 1] = a21;
        r_b1[js * 2 + 2] = a12; r_b1[js * 2 + 3] = a22;
        r_b2[js * 2 + 0] = a12; r_b2[js * 2 + 1] = a22;
        r_b2[js * 2 + 2] = a32; r_b2[js * 2 + 3] = a42;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = r_a1[is * 4 + 0]; a21 = r_a1[is * 4 + 1];
            a31 = r_a1[is * 4 + 2]; a41 = r_a1[is * 4 + 3];
            r_b1[is * 4 + 0] = a11; r_b1[is * 4 + 1] = a21;
            r_b1[is * 4 + 2] = a31; r_b1[is * 4 + 3] = a41;
            r_c1[(is/2) * 4*m + 0] = a11; r_c1[(is/2) * 4*m + 1] = a21;
            r_c2[(is/2) * 4*m + 0] = a31; r_c2[(is/2) * 4*m + 1] = a41;
        }
        a11 = r_a1[js * 2 + 0]; a21 = r_a1[js * 2 + 1];
        r_b1[js * 2 + 0] = a11; r_b1[js * 2 + 1] = a21;
    }
}
}
