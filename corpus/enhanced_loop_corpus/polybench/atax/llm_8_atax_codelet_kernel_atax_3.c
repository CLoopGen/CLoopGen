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
for (i = 0; i < m; i += 2) {
    tmp[i] = 0.;
    if (i + 1 < m) tmp[i+1] = 0.;
    for (j = 0; j < n; j++) {
        tmp[i] += A[i][j] * x[j];
        if (i + 1 < m) tmp[i+1] += A[i+1][j] * x[j];
    }
    for (j = 0; j < n; j++) {
        y[j] += A[i][j] * tmp[i];
        if (i + 1 < m) y[j] += A[i+1][j] * tmp[i+1];
    }
}
}
