#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern double x[2000];
extern double y[2000];
extern int i;
extern int j;
extern double w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    w = y[n - 1 - i];
    for (j = n - i; j < n; j++)
        w -= A[n - 1 - i][j] * x[j];
    x[n - 1 - i] = w / A[n - 1 - i][n - 1 - i];
}
}
