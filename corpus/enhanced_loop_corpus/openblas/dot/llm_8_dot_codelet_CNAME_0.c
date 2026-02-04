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
    for (j = i; j < n1; j += 8) {
        dot += y[j] * x[j];
        if (j + 1 < n1) dot += y[j + 1] * x[j + 1];
        if (j + 2 < n1) dot += y[j + 2] * x[j + 2];
        if (j + 3 < n1) dot += y[j + 3] * x[j + 3];
        if (j + 4 < n1) dot += y[j + 4] * x[j + 4];
        if (j + 5 < n1) dot += y[j + 5] * x[j + 5];
        if (j + 6 < n1) dot += y[j + 6] * x[j + 6];
        if (j + 7 < n1) dot += y[j + 7] * x[j + 7];
    }
    i = j; // update global index
}
