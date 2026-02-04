#include <stdio.h>

typedef long BLASLONG;

extern float *x;
extern float *y;
extern BLASLONG i;
extern float dot;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    BLASLONG limit = n1 - 3;
    for (; i < limit; i += 4) {
        float temp1 = y[i] * x[i];
        float temp2 = y[i + 1] * x[i + 1];
        dot += temp1 + temp2 + y[i + 2] * x[i + 2] + y[i + 3] * x[i + 3];
    }
    // Handle remaining elements with a simplified control path
    for (; i < n1; i++) {
        dot += y[i] * x[i];
    }
}
