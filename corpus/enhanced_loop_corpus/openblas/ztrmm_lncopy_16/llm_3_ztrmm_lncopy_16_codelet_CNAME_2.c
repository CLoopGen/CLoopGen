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
// Variant 2: Strided memory access - interleave source pointers to simulate strided gather pattern
float *sources[8] = {a01, a02, a03, a04, a05, a06, a07, a08};

for (ii = 0; ii < 8; ii++) {
    for (BLASLONG j = 0; j < 8; j++) {
        b[j * 2 + 0] = sources[j][0];
        b[j * 2 + 1] = sources[j][1];
    }
    // Advance all source pointers
    for (BLASLONG j = 0; j < 8; j++) {
        sources[j] += 2;
    }
    b += 16;
}
}
