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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 16; ii++) {
        float sum1 = *(a01 + 0) * 1.5f;
        float sum2 = *(a02 + 0) * 1.5f;
        float sum3 = *(a03 + 0) * 1.5f;
        float sum4 = *(a04 + 0) * 1.5f;
        float sum5 = *(a05 + 0) * 1.5f;
        float sum6 = *(a06 + 0) * 1.5f;
        float sum7 = *(a07 + 0) * 1.5f;
        float sum8 = *(a08 + 0) * 1.5f;
        b[0] = sum1 + sum2;
        b[1] = sum3 + sum4;
        b[2] = sum5 + sum6;
        b[3] = sum7 + sum8;
        a01++;
        a02++;
        a03++;
        a04++;
        a05++;
        a06++;
        a07++;
        a08++;
        b += 4;
    }
}
