#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern double b[2000];
extern double y[2000];
extern int i;
extern int j;
extern double w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= n; i++) {
    w = b[i-1];
    for (j = 0; j < i-1; j++)
        w -= A[i-1][j] * y[j];
    y[i-1] = w;
}
}
