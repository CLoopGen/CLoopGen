#include <stdio.h>

typedef long BLASLONG;

extern float *x;
extern float *y;
extern BLASLONG i;
extern float dot;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_dot = dot;
    for (; i < n1; i += 4) {
        float prod = y[i] * x[i];
        local_dot += prod;
        prod = y[i + 1] * x[i + 1];
        local_dot += prod;
        prod = y[i + 2] * x[i + 2];
        local_dot += prod;
        prod = y[i + 3] * x[i + 3];
        local_dot += prod;
    }
    dot = local_dot;
}
