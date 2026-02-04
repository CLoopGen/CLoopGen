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
double temp_y[1300];
for (i = 0; i < n; i++) {
    temp_y[i] = 0.0;
}
for (i = 0; i < n; i++) {
    tmp[i] = 0.0;
    for (j = 0; j < n; j++) {
        tmp[i] += A[i][j] * x[j];
    }
}
for (j = 0; j < n; j++) {
    for (i = 0; i < n; i++) {
        temp_y[i] += B[i][j] * x[j];
    }
}
for (i = 0; i < n; i++) {
    y[i] = alpha * tmp[i] + beta * temp_y[i];
}
}
