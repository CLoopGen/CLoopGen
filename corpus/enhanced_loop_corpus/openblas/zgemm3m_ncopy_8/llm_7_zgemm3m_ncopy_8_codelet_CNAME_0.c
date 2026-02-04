#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG m;
extern BLASLONG i;
extern float *a_offset1;
extern float *a_offset2;
extern float *a_offset3;
extern float *a_offset4;
extern float *a_offset5;
extern float *a_offset6;
extern float *a_offset7;
extern float *a_offset8;
extern float *b_offset;
extern float a1;
extern float a2;
extern float a3;
extern float a4;
extern float a5;
extern float a6;
extern float a7;
extern float a8;
extern float a9;
extern float a10;
extern float a11;
extern float a12;
extern float a13;
extern float a14;
extern float a15;
extern float a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float prev_sum = 0.0f;
for (i = 0; i < m; i++) {
    a1 = *(a_offset1 + 0);
    a2 = *(a_offset1 + 1);
    a3 = *(a_offset2 + 0);
    a4 = *(a_offset2 + 1);
    a5 = *(a_offset3 + 0);
    a6 = *(a_offset3 + 1);
    a7 = *(a_offset4 + 0);
    a8 = *(a_offset4 + 1);
    a9 = *(a_offset5 + 0);
    a10 = *(a_offset5 + 1);
    a11 = *(a_offset6 + 0);
    a12 = *(a_offset6 + 1);
    a13 = *(a_offset7 + 0);
    a14 = *(a_offset7 + 1);
    a15 = *(a_offset8 + 0);
    a16 = *(a_offset8 + 1);
    float sum1 = (a1 + a2) + prev_sum;
    float sum2 = (a3 + a4) + prev_sum;
    float sum3 = (a5 + a6) + prev_sum;
    float sum4 = (a7 + a8) + prev_sum;
    float sum5 = (a9 + a10) + prev_sum;
    float sum6 = (a11 + a12) + prev_sum;
    float sum7 = (a13 + a14) + prev_sum;
    float sum8 = (a15 + a16) + prev_sum;
    *(b_offset + 0) = sum1;
    *(b_offset + 1) = sum2;
    *(b_offset + 2) = sum3;
    *(b_offset + 3) = sum4;
    *(b_offset + 4) = sum5;
    *(b_offset + 5) = sum6;
    *(b_offset + 6) = sum7;
    *(b_offset + 7) = sum8;
    prev_sum = sum1;
    a_offset1 += 2;
    a_offset2 += 2;
    a_offset3 += 2;
    a_offset4 += 2;
    a_offset5 += 2;
    a_offset6 += 2;
    a_offset7 += 2;
    a_offset8 += 2;
    b_offset += 8;
}
}
