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
for (i = 0; i < n; i++) {
    tmp[i] = 0.;
    y[i] = 0.;
    for (j = 0; j < n; j += 2) {
        tmp[i] += A[i][j] * x[j];
        y[i] += B[i][j] * x[j];
        if (j+1 < n) {
            tmp[i] += A[i][j+1] * x[j+1];
            y[i] += B[i][j+1] * x[j+1];
        }
    }
    y[i] = alpha * tmp[i] + beta * y[i];
}
}
