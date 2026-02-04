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
for (ii = 0; ii < i; ii++) {
    // Variant 2: Strided memory access - interleave source reads with stride of 16 elements
    // Simulate a transposed or strided layout where each aXX represents a column in a matrix
    float *sources[16] = {a01, a02, a03, a04, a05, a06, a07, a08,
                          a09, a10, a11, a12, a13, a14, a15, a16};

    for (BLASLONG k = 0; k < 2; k++) {
        for (BLASLONG j = 0; j < 16; j++) {
            b[k * 16 + j] = *(sources[j] + k);
        }
    }

    a01 += 2; a02 += 2; a03 += 2; a04 += 2;
    a05 += 2; a06 += 2; a07 += 2; a08 += 2;
    a09 += 2; a10 += 2; a11 += 2; a12 += 2;
    a13 += 2; a14 += 2; a15 += 2; a16 += 2;
    b += 32;
}
}
