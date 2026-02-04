#include <stdio.h>

#include <inttypes.h>

extern float *x;
extern float *y;
extern float *var;
extern int N;
extern int i;
extern double s;
extern double sx;
extern double sy;
extern double sxx;
extern double sxy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < N; j += 2) {
    i = j;
    s += 1. / var[i];
    sx += x[i] / var[i];
    sy += y[i] / var[i];
    sxx += x[i] * x[i] / var[i];
    sxy += x[i] * y[i] / var[i];
    if (j + 1 < N) {
        i = j + 1;
        s += 1. / var[i];
        sx += x[i] / var[i];
        sy += y[i] / var[i];
        sxx += x[i] * x[i] / var[i];
        sxy += x[i] * y[i] / var[i];
    }
}
}
