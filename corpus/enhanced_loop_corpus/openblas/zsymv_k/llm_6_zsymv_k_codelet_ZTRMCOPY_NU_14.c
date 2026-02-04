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
    a += 2 * lda;
    bb1 = b1 + 0 * m;
    bb2 = b1 + 2 * m;
    b1 += 4 * m;
    cc1 = b2 + 0 * m;
    cc2 = b2 + 2 * m;
    b2 += 4;
    if (m - js >= 2) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a31 = *(aa1 + 2);
            a41 = *(aa1 + 3);
            a12 = *(aa2 + 0);
            a22 = *(aa2 + 1);
            a32 = *(aa2 + 2);
            a42 = *(aa2 + 3);
            // Introduce artificial WAW dependency by reordering and delaying write
            float temp11 = a11, temp21 = a21, temp31 = a31, temp41 = a41;
            float temp12 = a12, temp22 = a22, temp32 = a32, temp42 = a42;
            aa1 += 4;
            aa2 += 4;
            // Delayed writes to create different write-after-write pattern
            *(bb1 + 0) = temp11;
            *(bb1 + 1) = temp21;
            *(bb1 + 2) = temp31;
            *(bb1 + 3) = temp41;
            *(bb2 + 0) = temp12;
            *(bb2 + 1) = temp22;
            *(bb2 + 2) = temp32;
            *(bb2 + 3) = temp42;
            *(cc1 + 0) = temp11;
            *(cc1 + 1) = temp21;
            *(cc1 + 2) = temp12;
            *(cc1 + 3) = temp22;
            *(cc2 + 0) = temp31;
            *(cc2 + 1) = temp41;
            *(cc2 + 2) = temp32;
            *(cc2 + 3) = temp42;
            bb1 += 4;
            bb2 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        a12 = *(aa2 + 0);
        a22 = *(aa2 + 1);
        a32 = *(aa2 + 2);
        a42 = *(aa2 + 3);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
        *(bb1 + 2) = a12;
        *(bb1 + 3) = a22;
        *(bb2 + 0) = a12;
        *(bb2 + 1) = a22;
        *(bb2 + 2) = a32;
        *(bb2 + 3) = a42;
    }
    if (m - js == 1) {
        for (is = 0; is < js; is += 2) {
            a11 = *(aa1 + 0);
            a21 = *(aa1 + 1);
            a31 = *(aa1 + 2);
            a41 = *(aa1 + 3);
            aa1 += 4;
            // Introduce WAR-like behavior via temporary variables before final store
            float t1 = a11, t2 = a21, t3 = a31, t4 = a41;
            *(bb1 + 0) = t1;
            *(bb1 + 1) = t2;
            *(bb1 + 2) = t3;
            *(bb1 + 3) = t4;
            *(cc1 + 0) = t1;
            *(cc1 + 1) = t2;
            *(cc2 + 0) = t3;
            *(cc2 + 1) = t4;
            bb1 += 4;
            cc1 += 4 * m;
            cc2 += 4 * m;
        }
        a11 = *(aa1 + 0);
        a21 = *(aa1 + 1);
        *(bb1 + 0) = a11;
        *(bb1 + 1) = a21;
    }
}
}
