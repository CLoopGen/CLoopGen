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
for (ii = 0; ii < i; ii++) {
    // Variant 2: Strided memory access - interleave pointers to simulate strided reads
    float *ptrs[8] = {a01, a02, a03, a04, a05, a06, a07, a08};
    for (BLASLONG j = 0; j < 8; j++) {
        b[j*2 + 0] = ptrs[j][0];
        b[j*2 + 1] = ptrs[j][1];
    }
    a01 += 2; a02 += 2; a03 += 2; a04 += 2;
    a05 += 2; a06 += 2; a07 += 2; a08 += 2;
    b += 16;
}
}
