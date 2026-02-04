#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1900][2100];
extern double x[2100];
extern double y[2100];
extern double tmp[1900];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    double temp_val = 0.0;
    for (j = 0; j < n; j++)
        temp_val += A[i][j] * x[j];
    tmp[i] = temp_val;
    for (j = 0; j < n; j++)
        y[j] += A[i][j] * tmp[i];
}
}
