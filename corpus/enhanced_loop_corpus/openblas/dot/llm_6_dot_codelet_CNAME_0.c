#include <stdio.h>

typedef long BLASLONG;

extern float *x;
extern float *y;
extern BLASLONG i;
extern float dot;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp1 = 0.0f, temp2 = 0.0f, temp3 = 0.0f, temp4 = 0.0f;
    for (; i < n1; i += 4) {
        temp1 += y[i] * x[i];
        temp2 += y[i + 1] * x[i + 1];
        temp3 += y[i + 2] * x[i + 2];
        temp4 += y[i + 3] * x[i + 3];
    }
    dot += temp1 + temp2 + temp3 + temp4;
}
