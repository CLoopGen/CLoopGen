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
        C[i][j] += alpha * A[i][k] * B[i][j]; // Additional computation to increase arithmetic intensity
    }
    for (k = 0; k < m; k += 2) { // Modified trip count: step by 2 to reduce iterations
        if (k + 1 < m) {
            for (j = 0; j <= i; j++) {
                double temp1 = A[j][k] * alpha * B[i][k] + B[j][k] * alpha * A[i][k];
                double temp2 = A[j][k+1] * alpha * B[i][k+1] + B[j][k+1] * alpha * A[i][k+1];
                C[i][j] += temp1 + temp2;
            }
        } else {
            for (j = 0; j <= i; j++) {
                C[i][j] += A[j][k] * alpha * B[i][k] + B[j][k] * alpha * A[i][k];
            }
        }
    }
}
}
