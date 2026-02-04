#include <stdio.h>

typedef long BLASLONG;

extern float *x;
extern float *y;
extern BLASLONG i;
extern float dot;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    BLASLONG stride = 8;
    BLASLONG offset = i % stride;
    for (BLASLONG k = i; k < n1; k += stride) {
        if (k >= i && k < n1) dot += y[k] * x[k];
        if (k+1 >= i && k+1 < n1) dot += y[k+1] * x[k+1];
        if (k+2 >= i && k+2 < n1) dot += y[k+2] * x[k+2];
        if (k+3 >= i && k+3 < n1) dot += y[k+3] * x[k+3];
        if (k+4 >= i && k+4 < n1) dot += y[k+4] * x[k+4];
        if (k+5 >= i && k+5 < n1) dot += y[k+5] * x[k+5];
        if (k+6 >= i && k+6 < n1) dot += y[k+6] * x[k+6];
        if (k+7 >= i && k+7 < n1) dot += y[k+7] * x[k+7];
    }
}
