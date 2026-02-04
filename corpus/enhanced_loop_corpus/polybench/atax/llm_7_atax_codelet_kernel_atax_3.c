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
double local_y[2100] = {0};
for (i = 0; i < m; i++) {
    double tmp_i = 0.0;
    for (j = 0; j < n; j++)
        tmp_i += A[i][j] * x[j];
    for (j = 0; j < n; j++)
        local_y[j] += A[i][j] * tmp_i;
}
for (j = 0; j < n; j++)
    y[j] += local_y[j];
}
