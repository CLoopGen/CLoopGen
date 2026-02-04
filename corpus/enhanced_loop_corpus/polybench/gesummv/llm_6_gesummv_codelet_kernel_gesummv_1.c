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
    double temp_tmp = 0.0;
    double temp_y = 0.0;
    for (j = 0; j < n; j++) {
        temp_tmp += A[i][j] * x[j];
        temp_y += B[i][j] * x[j];
    }
    y[i] = alpha * temp_tmp + beta * temp_y;
}
}
