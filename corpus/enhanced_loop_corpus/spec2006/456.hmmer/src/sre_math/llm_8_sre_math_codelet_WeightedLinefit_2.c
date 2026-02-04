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
    int i;
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            s += 1. / var[i] + 1. / var[i+1];
            sx += x[i] / var[i] + x[i+1] / var[i+1];
            sy += y[i] / var[i] + y[i+1] / var[i+1];
            sxx += (x[i] * x[i]) / var[i] + (x[i+1] * x[i+1]) / var[i+1];
            sxy += (x[i] * y[i]) / var[i] + (x[i+1] * y[i+1]) / var[i+1];
        } else {
            s += 1. / var[i];
            sx += x[i] / var[i];
            sy += y[i] / var[i];
            sxx += x[i] * x[i] / var[i];
            sxy += x[i] * y[i] / var[i];
        }
    }
}
