#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii += 2) {
        for (BLASLONG step = 0; step < 2 && (ii + step) < i; step++) {
            BLASLONG offset = ii + step;
            b[0] = *(a01 + step);
            b[1] = *(a02 + step);
            b[2] = *(a03 + step);
            b[3] = *(a04 + step);
            b[4] = *(a05 + step);
            b[5] = *(a06 + step);
            b[6] = *(a07 + step);
            b[7] = *(a08 + step);
            b += 8;
        }
        a01 += 2;
        a02 += 2;
        a03 += 2;
        a04 += 2;
        a05 += 2;
        a06 += 2;
        a07 += 2;
        a08 += 2;
    }
}
