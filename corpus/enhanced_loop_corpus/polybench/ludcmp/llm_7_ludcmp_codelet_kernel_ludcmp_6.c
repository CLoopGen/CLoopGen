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
double temp[2000];
for (i = 0; i < n; i++) {
    temp[i] = b[i];
    for (j = 0; j < i; j++)
        temp[i] -= A[i][j] * y[j];
}
for (i = 0; i < n; i++) {
    y[i] = temp[i];
}
}
