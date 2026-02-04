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
    tmp[i] = 0.;
    for (j = 0; j < n; j += 2) {
        tmp[i] += A[i][j] * x[j];
        if (j + 1 < n) tmp[i] += A[i][j+1] * x[j+1];
    }
    for (j = 0; j < n; j++) {
        y[j] = y[j] + A[i][j] * tmp[i] * 1.5; // Increased arithmetic intensity
    }
}
}
