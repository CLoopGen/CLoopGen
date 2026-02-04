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
for (i = 0; i < n && i < 100; i++) {
    w = b[i];
    for (j = i - 1; j >= 0; j--)
        w -= A[i][j] * y[j];
    y[i] = w;
    y[i] *= (i % 2 == 0) ? 1.0 : 1.5;
}
}
