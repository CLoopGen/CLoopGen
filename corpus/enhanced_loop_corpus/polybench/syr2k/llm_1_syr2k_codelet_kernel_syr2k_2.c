#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double alpha;
extern double beta;
extern double C[1200][1200];
extern double A[1200][1000];
extern double B[1200][1000];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
        C[i][j] *= beta;
        for (k = 0; k < m; k++) {
            double temp1 = A[j][k] * alpha * B[i][k];
            double temp2 = B[j][k] * alpha * A[i][k];
            C[i][j] += temp1 + temp2;
        }
    }
}
for (i = 0; i < n; i++) {
    for (k = 0; k < m; k++) {
        for (j = 0; j <= i; j++) {
            C[i][j] += A[j][k] * alpha * B[i][k] + B[j][k] * alpha * A[i][k];
        }
    }
}
}
