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
    for (j = 0; j < n; j++) {
        if (A[i][j] != 0.0) {
            tmp[i] = A[i][j] * x[j] + tmp[i];
        }
        if (B[i][j] != 0.0) {
            y[i] = B[i][j] * x[j] + y[i];
        }
    }
    y[i] = alpha * tmp[i] + beta * y[i];
}
}
