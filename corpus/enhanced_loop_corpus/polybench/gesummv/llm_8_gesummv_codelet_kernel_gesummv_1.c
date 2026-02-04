#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double alpha;
extern double beta;
extern double A[1300][1300];
extern double B[1300][1300];
extern double tmp[1300];
extern double x[1300];
extern double y[1300];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    tmp[i] = 0.;
    y[i] = 0.;
    if (i+1 < n) {
        tmp[i+1] = 0.;
        y[i+1] = 0.;
    }
    for (j = 0; j < n; j++) {
        tmp[i] += A[i][j] * x[j];
        y[i] += B[i][j] * x[j];
        if (i+1 < n) {
            tmp[i+1] += A[i+1][j] * x[j];
            y[i+1] += B[i+1][j] * x[j];
        }
    }
    y[i] = alpha * tmp[i] + beta * y[i];
    if (i+1 < n) {
        y[i+1] = alpha * tmp[i+1] + beta * y[i+1];
    }
}
}
