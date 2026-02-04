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
    for (j = i; j < n1 && j + 7 < n1; j += 8) {
        float sum1 = y[j] * x[j] + y[j + 1] * x[j + 1];
        float sum2 = y[j + 2] * x[j + 2] + y[j + 3] * x[j + 3];
        float sum3 = y[j + 4] * x[j + 4] + y[j + 5] * x[j + 5];
        float sum4 = y[j + 6] * x[j + 6] + y[j + 7] * x[j + 7];
        dot += sum1 + sum2 + sum3 + sum4;
    }
    i = j;
}
