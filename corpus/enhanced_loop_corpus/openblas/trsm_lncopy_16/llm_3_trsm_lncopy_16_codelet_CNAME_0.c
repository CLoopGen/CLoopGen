#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern BLASLONG jj;
extern BLASLONG k;
extern float *a1;
extern float *a2;
extern float *a3;
extern float *a4;
extern float *a5;
extern float *a6;
extern float *a7;
extern float *a8;
extern float *a9;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    BLASLONG offset = ii - jj;
    if ((ii >= jj) && (offset < 16)) {
        for (k = 0; k <= offset; k++) {
            if (k < offset) {
                b[k] = a1[k * lda];
            } else {
                b[k] = 1.F / a1[k * lda];
            }
        }
    }
    if (offset >= 16) {
        // Use strided memory access pattern: interleave source pointers
        for (k = 0; k < 16; k++) {
            float *sources[] = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16};
            b[k] = sources[k][0];
        }
    }
    // Update all array heads using unit stride
    a1 += 1;
    a2 += 1;
    a3 += 1;
    a4 += 1;
    a5 += 1;
    a6 += 1;
    a7 += 1;
    a8 += 1;
    a9 += 1;
    a10 += 1;
    a11 += 1;
    a12 += 1;
    a13 += 1;
    a14 += 1;
    a15 += 1;
    a16 += 1;
    b += 16;
    ii++;
}
}
