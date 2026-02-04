#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;
extern float *a09;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 4; ii++) {
        for (BLASLONG jj = 0; jj < 4; jj++) {
            BLASLONG idx = ii * 4 + jj;
            float *a_ptrs[] = {a01, a02, a03, a04, a05, a06, a07, a08,
                               a09, a10, a11, a12, a13, a14, a15, a16};
            b[0]  = *(a_ptrs[idx*2+0] + 0);
            b[1]  = *(a_ptrs[idx*2+0] + 1);
            b[2]  = *(a_ptrs[idx*2+1] + 0);
            b[3]  = *(a_ptrs[idx*2+1] + 1);
            b += 4;
        }
        a01 += 8; a02 += 8; a03 += 8; a04 += 8;
        a05 += 8; a06 += 8; a07 += 8; a08 += 8;
        a09 += 8; a10 += 8; a11 += 8; a12 += 8;
        a13 += 8; a14 += 8; a15 += 8; a16 += 8;
        b -= 128 - 32;
    }
}
