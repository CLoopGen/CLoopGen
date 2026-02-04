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
    aa1 = a + 0 * lda;
    aa2 = a + 1 * lda;
    a += 2 * lda;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 1 * m;
    b1 += 2 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 1 * m;
    b2 += 2;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            // Remove redundant loads and fuse operations: reduce RAW dependencies via reuse
            float temp1 = *(aa1 + 0);
            float temp2 = *(aa1 + 1);
            float temp3 = *(aa2 + 0);
            float temp4 = *(aa2 + 1);
            aa1 += 2;
            aa2 += 2;
            // Combine updates: eliminate intermediate variable usage, write directly
            *(bb1 + 0) = temp1;
            *(bb1 + 1) = temp2;
            *(bb2 + 0) = temp3;
            *(bb2 + 1) = temp4;
            *(cc1 + 0) = temp1;
            *(cc1 + 1) = temp3;
            *(cc2 + 0) = temp2;
            *(cc2 + 1) = temp4;
            bb1 += 2;
            bb2 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }
        // Eliminate partial redundancy in scalar usage
        *(bb1 + 0) = *(aa1 + 0);
        *(bb1 + 1) = *(aa2 + 0);
        *(bb2 + 0) = *(aa2 + 0);
        *(bb2 + 1) = *(aa2 + 1);
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            float temp = *(aa1 + 0);
            *(bb1 + 0) = temp;
            *(cc1 + 0) = temp;
            temp = *(aa1 + 1);
            *(bb1 + 1) = temp;
            *(cc2 + 0) = temp;
            aa1 += 2;
            bb1 += 2;
            cc1 += 2 * m;
            cc2 += 2 * m;
        }
        *(bb1 + 0) = *(aa1 + 0);
    }
}
}
