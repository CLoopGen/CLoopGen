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
    // Variant 2: Strided memory access - interleave source reads with stride of 16 elements
    float *sources[32]; // Double buffer to simulate strided pattern across iterations

    // Initialize source pointers in a flattened strided layout
    for (ii = 0; ii < 16; ii++) {
        sources[ii * 2 + 0] = a01 + ii;
        sources[ii * 2 + 1] = a02 + ii;
    }

    for (ii = 0; ii < 16; ii++) {
        for (BLASLONG j = 0; j < 32; j++) {
            b[j] = *(sources[j]);
            sources[j] += 1; // Move each source by 1 float per iteration
        }
        b += 32;
    }
}
