#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x1[2000];
extern double y_1[2000];
extern double A[2000][2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    double sum1 = 0.0, sum2 = 0.0;
    for (j = 0; j < n - 1; j += 2) {
        sum1 += A[i][j] * y_1[j];
        sum2 += A[i][j+1] * y_1[j+1];
    }
    if (j == n - 1) {
        sum1 += A[i][j] * y_1[j];
    }
    x1[i] = x1[i] + sum1 + sum2;
}
}
