#include <stdio.h>

typedef long BLASLONG;

extern float *x;
extern float *y;
extern BLASLONG i;
extern float dot;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    BLASLONG j = i;
    BLASLONG end = n1;
    for (; j < end; j += 4) {
        if (j + 3 >= end) break;
        float s0 = y[j] * x[j];
        float s1 = y[j + 1] * x[j + 1];
        float s2 = y[j + 2] * x[j + 2];
        float s3 = y[j + 3] * x[j + 3];
        dot += s0 + s1 + s2 + s3;
    }
    i = j; // Update outer state
}
