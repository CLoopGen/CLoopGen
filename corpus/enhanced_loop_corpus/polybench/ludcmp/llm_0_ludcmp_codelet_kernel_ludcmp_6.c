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
for (i = 0; i < n; i++) {
    w = b[i];
    j = 0;
    for (; j < i; j++) {
        w -= A[i][j] * y[j];
    }
    y[i] = w;
}
}
