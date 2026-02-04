#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
        double sum = 0.0;
        for (k = 0; k < j; k++) {
            sum += A[i][k] * A[k][j];
        }
        A[i][j] = (A[i][j] - sum) / A[j][j];
    }
    for (j = i; j < n; j++) {
        double sum = 0.0;
        for (k = 0; k < i; k++) {
            sum += A[i][k] * A[k][j];
        }
        A[i][j] -= sum;
    }
}
}
