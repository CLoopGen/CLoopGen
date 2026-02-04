#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii += 2) {
        for (BLASLONG j = 0; j < 2 && (ii + j) < i; j++) {
            b[0] = *(a01 + 0);
            b[1] = *(a01 + 1);
            b[2] = *(a02 + 0);
            b[3] = *(a02 + 1);
            b[4] = *(a03 + 0);
            b[5] = *(a03 + 1);
            b[6] = *(a04 + 0);
            b[7] = *(a04 + 1);
            a01 += 2;
            a02 += 2;
            a03 += 2;
            a04 += 2;
            b += 8;
        }
    }
}
