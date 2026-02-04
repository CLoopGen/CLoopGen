#include <stdio.h>

typedef long BLASLONG;

extern float *x;
extern float *y;
extern BLASLONG i;
extern float dot;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    BLASLONG j;
    float sum = 0.0f;
    for (j = 0; j < n1 - i; j += 4) {
        BLASLONG idx = i + j;
        sum += y[idx] * x[idx] + y[idx + 1] * x[idx + 1] + y[idx + 2] * x[idx + 2] + y[idx + 3] * x[idx + 3];
    }
    dot += sum;
}
