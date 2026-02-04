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
for (i = n - 1; i >= 0; i--) {
    w = y[i];
    for (j = n - 1; j > i; j--)
        w -= A[i][j] * x[j];
    x[i] = w / A[i][i];
}
}
